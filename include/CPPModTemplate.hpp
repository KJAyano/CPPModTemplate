#pragma once

#include <format>

#include <DynamicOutput/Output.hpp>
#include <Mod/CppUserModBase.hpp>
#include <Unreal/UObject.hpp>
#include <Unreal/UObjectArray.hpp>
#include <Unreal/UObjectGlobals.hpp>

#include "version.h"

namespace MyMods
{
    using namespace RC;
    using namespace Unreal;

    class CPPModTemplate : public RC::CppUserModBase
    {
    public:
        CPPModTemplate()
        {
            ModVersion = std::format(STR("{}.{}.{}"), VERSION_MAJOR, VERSION_MINOR, VERSION_REVISION);
            ModName = STR("CPPModTemplate");
            ModAuthors = STR("KJAyano");
            ModDescription = STR("A basic template C++ mod");

            Output::send<LogLevel::Warning>(STR("[CPPModTemplate]: Init.\n"));
        }

        auto on_program_start() -> void override
        {
        }

        auto on_dll_load(std::wstring_view dll_name) -> void override
        {
        }

        auto on_unreal_init() -> void override
        {
            auto object = UObjectGlobals::StaticFindObject<UObject*>(nullptr, nullptr, STR("/Script/CoreUObject.Object"));

            if (object == nullptr)
            {
                Output::send<LogLevel::Error>(STR("[CPPModTemplate]: Could not find the CoreUObject Object class.\n"));
                return;
            }

            auto object_item = object->GetObjectItem();
            if (object_item == nullptr || !UObjectArray::IsValid(object_item, false))
            {
                Output::send<LogLevel::Error>(STR("[CPPModTemplate]: The CoreUObject Object class is not valid.\n"));
                return;
            }

            Output::send<LogLevel::Verbose>(STR("Object Name: {}\n"), object->GetFullName());
        }
    };
}
