#include "CPPModTemplate.hpp"

#include <Mod/CppUserModBase.hpp>
#define MOD_EXPORT __declspec(dllexport)

extern "C"
{
    MOD_EXPORT RC::CppUserModBase* start_mod()
    {
        return new MyMods::CPPModTemplate();
    }

    MOD_EXPORT void uninstall_mod(RC::CppUserModBase* mod)
    {
        delete mod;
    }
}
