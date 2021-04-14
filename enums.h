#ifndef ENUMS_H_
#define ENUMS_H_

#define ENUM_ITEM(name) name,
#define DEFINE_ENUM(name, list) \
typedef enum { \
    list(ENUM_ITEM) \
}name;

#define ToSTR(S) #S,
#define ENUM2STR_NAMES(name, list) \
   const char *name##_str[] = { \
       list(ToSTR) \
   };

#define STR_CASE(name) case name: return #name;
#define STR_FUNC(name, list) \
    inline const char* e2str(name n){ \
        switch(n) { \
            list(STR_CASE) \
            default: return ""; \
        } \
    }

////////////////////////////////////////////////////////
#define ENUM_LIST_e_parameters(T) \
T(param1) \
T(param2) \
T(param3) \
T(param4) \
/* Add new parameters into Enum right before the last element */ \
T(max_params)
DEFINE_ENUM(t_e_parameters, ENUM_LIST_e_parameters) STR_FUNC(t_e_parameters, ENUM_LIST_e_parameters)
#undef ENUM_LIST_e_parameters

////////////////////////////////////////////////////////
#define ENUM_LIST_e_another_parameters(T) \
T(param1_) \
T(param2_) \
T(param3_) \
T(param4_) \
/* Add new parameters into Enum right before the last element */ \
T(max_params_)
DEFINE_ENUM(t_e_another_parameters, ENUM_LIST_e_another_parameters) STR_FUNC(t_e_another_parameters, ENUM_LIST_e_another_parameters)
#undef ENUM_LIST_e_another_parameters

#endif