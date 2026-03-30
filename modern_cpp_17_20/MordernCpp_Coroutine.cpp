#include<coroutine>
#include<iostream>
//from Cpp 20, comes Coroutine, A coroutine is a function that can suspend itself.
// it is like a async in python, but at lower level
// if a function has co_await, co_return, co_yield, then it is a coroutine function,
// so, coroutine function are widely used in IO, networking programming


// a very simple example to show how coroutine work
// return_type is setup to faciliate co_return, co_yield, co_await


struct return_type {// could be a class as well, merely a wrapper on promise_type
    struct promise_type {// promise_type is required by complier, with exact same writing
                         //promise type must be defined inside the type returned by the coroutine
        std::string input_data { };//
        std::string output_data { };

        return_type get_return_object() noexcept {
            std::cout<<"get_return_object"<<std::endl;
            return return_type{ *this };
        }

        void return_void() noexcept {std::cout<<"return void"<<std::endl;}//if co_return give nothing, then use this return_void, 
                                      //if co_return give a value, then use return_value,


        std::suspend_always yield_value(
                                std::string msg) noexcept {
                    std::cout << "yield_value\n";
                    output_data = std::move(msg);
                    return {};
        }// this function is only for co_yield, 

        std::suspend_always initial_suspend() noexcept {//it is a must
            std::cout<<"initial_suspend"<<std::endl;
            return {};
        }
        std::suspend_always final_suspend() noexcept {//it is a must
            std::cout<<"final_suspend"<<std::endl;
            return {};
        }
        void unhandled_exception() noexcept {std::cout<<"unhandled_exception"<<std::endl;}// it is a must. it deals with exception in coroutine, 
                                              //if exception is thrown but not caught, then call this function
        
        auto await_transform(std::string) noexcept {//this function is only for co_await
            struct awaiter {
                promise_type& promise;

                bool await_ready() const noexcept {
                    std::cout<<"awaiter::await_ready"<<std::endl;
                    return true;
                }
                std::string await_resume() const noexcept {
                    std::cout<<"awaiter::await_resume"<<std::endl;
                    return std::move(promise.input_data);
                }
                void await_suspend(std::coroutine_handle<
                                    promise_type>) const noexcept {
                    std::cout<<"awaiter::await_suspend"<<std::endl;
                }
            };

            std::cout<<"await_transform return awaiter"<<std::endl;            
            return awaiter(*this);//return an awaiter object,initilized with 'promise_type& promise', promise = this
        }
    };

    std::coroutine_handle<promise_type> handle{};//this initialization is not a must ,but recommended
    
    explicit return_type(promise_type& promise)
      : handle{ std::coroutine_handle<
                         promise_type>::from_promise(promise)} {//initialize the member variable handle from the promise
            std::cout<<"return_type, initilize handle"<<std::endl;
    }

    ~return_type() noexcept {
        if (handle) {
            handle.destroy();
        }
    }
    
    std::string get() {// for co_yield, get the value from co_yield, and trigger the co_yield to resume work
        std::cout << "get()\n";
        if (!handle.done()) {
            handle.resume();
        }
        return std::move(handle.promise().output_data);
    }

    void put(std::string msg) {// for co_await, put in some value to trigger the co_await to resume work
        handle.promise().input_data = std::move(msg);
        if (!handle.done()) {
            handle.resume();
        }
    }
};


return_type donothing_func() {
    co_return;
}

return_type coyield_func() {
    co_yield "Hello from the coroutine";
    co_return;
}

return_type coawait_func() {
    std::cout << co_await std::string{ };
    co_return;
}

int main()
{
    donothing_func();
    std::cout<<"------------------"<<std::endl;
    auto c1 = coyield_func();
    std::cout<<c1.get()<<std::endl;
    std::cout<<"------------------"<<std::endl;
    auto c2 = coawait_func();
    c2.put("Hello from main\n");
    return 0;
}


//g++ -std=c++20 .\MordernCpp_Coroutine.cpp -o .\MordernCpp_Coroutine.exe; if ($LASTEXITCODE -eq 0) { .\MordernCpp_Coroutine.exe }
