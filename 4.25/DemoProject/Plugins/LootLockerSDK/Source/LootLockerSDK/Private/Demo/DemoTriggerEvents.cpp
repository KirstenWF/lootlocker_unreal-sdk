// Copyright (c) 2020 LootLocker

#include "Demo/DemoTriggerEvents.h"


void ADemoTriggerEvents::DemoTriggerEvent()
{
   ULootLockerSDKManager::TriggerEvent(Event, FTriggerEventResponseDelegate::CreateUObject(this, &ADemoTriggerEvents::OnTriggerEventCompleted));
}

void ADemoTriggerEvents::DemoGetTriggeredEvents()
{
   ULootLockerSDKManager::GetTriggeredEvents(FTriggersResponseDelegate::CreateUObject(this, &ADemoTriggerEvents::OnGetTriggeredEventsCompleted));
}

void ADemoTriggerEvents::OnTriggerEventCompleted(FTriggerEventResponse Response)
{
    if (Response.success)
    {
        UE_LOG(LogTemp, Verbose, TEXT("OnTriggerEvent Success"));
    }
    else
    {
        UE_LOG(LogTemp, Verbose, TEXT("OnTriggerEvent Failed"));
    }
}

void ADemoTriggerEvents::OnGetTriggeredEventsCompleted(FTriggersResponse Response)
{
    if (Response.success)
    {
        UE_LOG(LogTemp, Verbose, TEXT("OnGetTriggeredEvents Success"));
    }
    else
    {
        UE_LOG(LogTemp, Verbose, TEXT("OnGetTriggeredEvents Failed"));
    }
}
