// Copyright (c) 2021 LootLocker

#include "Demo/DemoCharacters.h"

void ADemoCharacters::GetCharacterLoadout()
{
   ULootLockerSDKManager::GetCharacterLoadout(FCharacterLoadoutResponse::CreateUObject(this, &ADemoCharacters::OnGetCharacterLoadoutCompleted));
}

void ADemoCharacters::EquipAssetToDefaultCharacter()
{
   ULootLockerSDKManager::EquipAssetToDefaultCharacter(InstanceId, FLootLockerCharacterDefaultResponse::CreateUObject(this, &ADemoCharacters::OnEquipAssetToDefaultCharacterCompleted));
}

void ADemoCharacters::EquipAssetToCharacterById()
{
   ULootLockerSDKManager::EquipAssetToCharacterById(CharacterId, AssetId, AssetVariationId, FLootLockerCharacterDefaultResponse::CreateUObject(this, &ADemoCharacters::OnEquipAssetToCharacterByIdCompleted));
}

void ADemoCharacters::UnEquipAssetToDefaultCharacter()
{
   ULootLockerSDKManager::UnEquipAssetToDefaultCharacter(InstanceId, FLootLockerCharacterDefaultResponse::CreateUObject(this, &ADemoCharacters::OnUnEquipAssetToDefaultCharacterCompleted));
}

void ADemoCharacters::UnEquipAssetToCharacterById()
{
   ULootLockerSDKManager::UnEquipAssetToCharacterById(CharacterId, InstanceId, FLootLockerCharacterDefaultResponse::CreateUObject(this, &ADemoCharacters::OnUnEquipAssetToCharacterByIdCompleted));
}

void ADemoCharacters::GetCurrentLoadoutToDefaultCharacter()
{
   ULootLockerSDKManager::GetCurrentLoadoutToDefaultCharacter(FCharacterLoadoutResponse::CreateUObject(this, &ADemoCharacters::OnGetCurrentLoadoutToDefaultCharacterCompleted));
}

void ADemoCharacters::GetOtherPlayersCurrentLoadoutToDefaultCharacter()
{
   ULootLockerSDKManager::GetOtherPlayersCurrentLoadoutToDefaultCharacter(OtherPlayerId, FCharacterLoadoutResponse::CreateUObject(this, &ADemoCharacters::OnGetOtherPlayersCurrentLoadoutToDefaultCharacterCompleted));
}

void ADemoCharacters::GetEquipableContextsToDefaultCharacter()
{
   ULootLockerSDKManager::GetEquipableContextsToDefaultCharacter(FContextDelegate::CreateUObject(this, &ADemoCharacters::OnGetEquipableContextsToDefaultCharacterCompleted));
}

void ADemoCharacters::GetEquipableContextsByCharacterId()
{
   ULootLockerSDKManager::GetEquipableContextsByCharacterId(OtherPlayerId, FContextDelegate::CreateUObject(this, &ADemoCharacters::OnGetEquipableContextsByCharacterIdCompleted));
}

void ADemoCharacters::UpdateCharacter()
{
    ULootLockerSDKManager::UpdateCharacter(CharacterId,IsDefault,CharacterName,FCharacterLoadoutResponse::CreateUObject(this, &ADemoCharacters::OnUpdatedCharacterLoadoutCompleted));
}


void ADemoCharacters::OnUpdatedCharacterLoadoutCompleted(FLootLockerCharacterLoadoutResponse Response)
{
    if (Response.success)
    {
        UE_LOG(LogTemp, Verbose, TEXT("OnGetCharacterLoadout Success"));
    }
    else
    {
        UE_LOG(LogTemp, Verbose, TEXT("OnGetCharacterLoadout Failed"));
    }
}

void ADemoCharacters::OnGetCharacterLoadoutCompleted(FLootLockerCharacterLoadoutResponse Response)
{
    if (Response.success)
    {
        UE_LOG(LogTemp, Verbose, TEXT("OnGetCharacterLoadout Success"));
    }
    else
    {
        UE_LOG(LogTemp, Verbose, TEXT("OnGetCharacterLoadout Failed"));
    }
}

void ADemoCharacters::OnEquipAssetToDefaultCharacterCompleted(FLootLockerResponse Response)
{
    if (Response.success)
    {
        UE_LOG(LogTemp, Verbose, TEXT("OnEquipAssetToDefaultCharacter Success"));
    }
    else
    {
        UE_LOG(LogTemp, Verbose, TEXT("OnEquipAssetToDefaultCharacter Failed"));
    }
}

void ADemoCharacters::OnEquipAssetToCharacterByIdCompleted(FLootLockerResponse Response)
{
    if (Response.success)
    {
        UE_LOG(LogTemp, Verbose, TEXT("OnEquipAssetToCharacterById Success"));
    }
    else
    {
        UE_LOG(LogTemp, Verbose, TEXT("OnEquipAssetToCharacterById Failed"));
    }
}

void ADemoCharacters::OnUnEquipAssetToDefaultCharacterCompleted(FLootLockerResponse Response)
{
    if (Response.success)
    {
        UE_LOG(LogTemp, Verbose, TEXT("OnUnEquipAssetToDefaultCharacterCompleted Success"));
    }
    else
    {
        UE_LOG(LogTemp, Verbose, TEXT("OnUnEquipAssetToDefaultCharacter Failed"));
    }
}

void ADemoCharacters::OnUnEquipAssetToCharacterByIdCompleted(FLootLockerResponse Response)
{
    if (Response.success)
    {
        UE_LOG(LogTemp, Verbose, TEXT("OnUnEquipAssetToCharacterById Success"));
    }
    else
    {
        UE_LOG(LogTemp, Verbose, TEXT("OnUnEquipAssetToCharacterById Failed"));
    }
}

void ADemoCharacters::OnGetCurrentLoadoutToDefaultCharacterCompleted(FLootLockerCharacterLoadoutResponse Response)
{
    if (Response.success)
    {
        UE_LOG(LogTemp, Verbose, TEXT("OnGetCurrentLoadoutToDefaultCharacter Success"));
    }
    else
    {
        UE_LOG(LogTemp, Verbose, TEXT("OnGetCurrentLoadoutToDefaultCharacter Failed"));
    }
}

void ADemoCharacters::OnGetOtherPlayersCurrentLoadoutToDefaultCharacterCompleted(FLootLockerCharacterLoadoutResponse Response)
{
    if (Response.success)
    {
        UE_LOG(LogTemp, Verbose, TEXT("OnGetOtherPlayersCurrentLoadoutToDefaultCharacter Success"));
    }
    else
    {
        UE_LOG(LogTemp, Verbose, TEXT("OnGetOtherPlayersCurrentLoadoutToDefaultCharacter Failed"));
    }
}

void ADemoCharacters::OnGetEquipableContextsToDefaultCharacterCompleted(FLootLockerGetContextResponse Response)
{
    if (Response.success)
    {
        UE_LOG(LogTemp, Verbose, TEXT("OnGetEquipableContextsToDefaultCharacter Success"));
    }
    else
    {
        UE_LOG(LogTemp, Verbose, TEXT("OnGetEquipableContextsToDefaultCharacter Failed"));
    }
}

void ADemoCharacters::OnGetEquipableContextsByCharacterIdCompleted(FLootLockerGetContextResponse Response)
{
    if (Response.success)
    {
        UE_LOG(LogTemp, Verbose, TEXT("OnGetEquipableContextsByCharacterId Success"));
    }
    else
    {
        UE_LOG(LogTemp, Verbose, TEXT("OnGetEquipableContextsByCharacterId Failed"));
    }
}
