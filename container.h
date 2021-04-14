#ifndef CONTAINER_H_
#define CONTAINER_H_

////////////////////////////////////////////////////////
using var_t = std::variant<std::string, double, int>;

// helper constant for the visitor
template<class> inline constexpr bool always_false_v = false;

class variant_container
{
private:
    std::unordered_map<std::string, std::optional<var_t>> params;

public:
    variant_container(){
    }

    template <typename T1>
    void init(int max_params){
        for(int i = 0; i < max_params; ++i){
            add((T1)i);
        }
    }

    template <typename T1>
    void add(T1 key){
        params[std::string{e2str(key)}] = std::nullopt;
    }

    template <typename T, typename T1>
    void setValue(T1 key, T value)
    {
        params[std::string{e2str(key)}] = value;
    }

    template <typename T, typename T1>
    T getValue(T1 key) const
    {
        auto it = params.find(std::string{e2str(key)});
        if (it == params.end())
            return {};

        if(it->second.has_value()){
            return std::get<T>(it->second.value());
        }

        return {};
    }

    template<typename T1>
    bool lookup(T1 key){
        auto it = params.find(std::string{e2str(key)});
        if (it == params.end())
            return false;

        return it->second.has_value();
    }

    void printall(){
        std::cout << "Number of params: " << params.size() << std::endl;
        for(auto& p: params){
            if(p.second.has_value()){
                std::visit([](auto&& arg) {
                    using T = std::decay_t<decltype(arg)>;
                    if constexpr (std::is_same_v<T, int>)
                        std::cout << typeid(T).name() <<" with value " << arg << '\n';
                    else if constexpr (std::is_same_v<T, double>)
                        std::cout << typeid(T).name() << " with value " << arg << '\n';
                    else if constexpr (std::is_same_v<T, std::string>)
                        std::cout << typeid(T).name() << " with value " << std::quoted(arg) << '\n';
                    else 
                        static_assert(always_false_v<T>, "non-exhaustive visitor!");
                }, p.second.value());
            }else{
                std::cout << p.first << " has no value\n";
            }
        }
    }
};

#endif