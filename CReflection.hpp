#include <tuple>
#include <map>
#include <functional>
#include <any>

class creflection
{
public:
    template<typename R, typename... Args>
    int regist_func(std::string func_name, const std::function<R(Args...)>& func)
    {
        using args_type = std::tuple<Args...>;
        if (funcs.find(func_name) != funcs.end())
        {
            return 1;
        }
        funcs[func_name] = [=](std::any args) -> void{
            if (args.type() != typeid(args_type))
            {
                std::cout << "cast error " << std::endl;
                return;
            }
            auto typed_args = std::any_cast<args_type>(args);
            std::apply(func, typed_args);
        };
        return 0;
    }
    template<typename... Args>
    int reflection_call(std::string func_name, Args... args)
    {
        std::tuple<Args...> tuple_args(args...);
        if (funcs.find(func_name) == funcs.end())
        {
            std::cout << "func not exists" << std::endl;
            return 1;
        }
        funcs[func_name](tuple_args);
        return 0;
    }
private:
    std::map<std::string, std::function<void(std::any)>> funcs;
};