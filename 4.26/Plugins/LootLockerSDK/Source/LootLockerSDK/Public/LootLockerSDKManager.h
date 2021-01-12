// Copyright (c) 2020 LootLocker

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameAPI/AuthenticationRequestHandler.h"
#include "HttpClient.h"
#include "LootLockerConfig.h"
#include "Engine/DataAsset.h"
#include "GameAPI/PlayerRequestHandler.h"
#include "GameAPI/CharacterRequestHandler.h"
#include "GameAPI/PersistentStorageRequestHandler.h"
#include "GameAPI/AssetsRequestHandler.h"
#include "GameAPI/AssetInstancesRequestHandler.h"
#include "GameAPI/UserGeneratedContentRequestHandler.h"
#include "GameAPI/MissionsRequestHandler.h"
#include "GameAPI/MapsRequestHandler.h"
#include "GameAPI/PurchasesRequestHandler.h"
#include "GameAPI/TriggerEventsRequestHandler.h"
#include "GameAPI/CollectablesRequestHandler.h"
#include "GameAPI/MessagesRequestHandler.h"

#include "LootLockerSDKManager.generated.h"

UCLASS(Blueprintable)
class LOOTLOCKERSDK_API ULootLockerSDKManager : public UObject
{
	GENERATED_BODY()

public:
    
    //==================================================
    //Authentication
    //==================================================
    
    /**
     * https://docs.lootlocker.io/game-api/#authentication-request
     * Register a session.
     *
     * @param PlayerId - the ID of the player on the platform the game is currently running on.
     * @param OnCompletedRequest - callback to be invoked with the server response.
     */
	static void StartSession(const FString& PlayerId, const FLootLockerSessionResponse& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#player-verification
    * If your game uses Player Verification, you need to call this endpoint before you can register a session.
    *
    * @param CachedSteamToken - platform-specific token.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
	static void VerifyPlayer(const FString& CachedSteamToken, const FLootLockerDefaultAuthenticationResponse& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#ending-a-session
    * Terminate the session on the LootLocker servers. Any further requests with this session's token will be rejected with an 401 Unauthroized error.
    *
    * @param PlayerId - the ID of the player on the platform the game is currently running on.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
	static void EndSession(const FString& PlayerId, const FLootLockerDefaultAuthenticationResponse& OnCompletedRequest);
    
    //==================================================
	//Player calls
    //==================================================
    
    /**
    * https://docs.lootlocker.io/game-api/#get-player-info
    * Get general information about the player, such as the XP, Level information and their account balance.
    *
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
	static void GetPlayerInfo(const FLootLockerPlayerInformationResponse& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#get-inventory-list
    * Get a paginated list of the players inventory.
    *
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
	static void GetInventory(const FLootLockerInventoryResponse& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#submit-xp
    * Receive xp, and award it to the player.
    *
    * @param Points - number of XP points to grant to the player.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
	static void SubmitXP(int Points, const FLootLockerSubmitXpResponse& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#get-other-players-xp-and-level
    * Get other players XP and level.
    *
    * @param GetRequests - request data.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
	static void GetOtherPlayerInfo(FLootLockerGetRequests& GetRequests, const FLootLockerPlayerInformationResponse& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#player-asset-notifications
    * Get assets that have been granted (given to) the player since the last time this endpoint was called.
    *
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
	static void CheckPlayerAssetActivationNotification(const FLootLockerAssetNotificationResponse& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#player-asset-deactivation-notifications
    * Get asset deactivations since the last time it's been checked.
    * Do not expect both replacement_asset_id and reason to have values at the same time. They can have, but it is not required.
    *
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
	static void CheckPlayerAssetDeactivationNotification(const FLootLockerAssetNotificationResponse& OnCompletedRequest);
    
    //==================================================
	//Characters
    //==================================================
    
    /**
    * https://docs.lootlocker.io/game-api/#character-loadouts
    * This call will return all characters loadouts for a game, and have some additional information on the characters.
    *
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
	static void GetCharacterLoadout(const FLootLockerCharacterLoadoutResponse& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#equip-asset-to-default-character
    * Equip an asset to the default character.
    *
    * @param InstanceId - the asset's instance_id that is returned from the inventory and loadout calls.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
	static void EquipAssetToDefaultCharacter(int InstanceId, const FLootLockerCharacterDefaultResponse& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#equip-asset-to-character-by-id
    * Equip an asset to the specified character.
    *
    * @param CharacterId - ID of the character to equip an asset to.
    * @param InstanceId - the asset's instance_id that is returned from the inventory and loadout calls.
    * @param AssetVariationId - the asset_variation_id.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
	static void EquipAssetToCharacterById(int CharacterId, int AssetId, int AssetVariationId, const FLootLockerCharacterDefaultResponse& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#unequip-asset-to-default-character
    * Unequip an asset from the default character.
    *
    * @param InstanceId - the asset's instance_id that is returned from the inventory and loadout calls.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
	static void UnEquipAssetToDefaultCharacter(int InstanceId, const FLootLockerCharacterDefaultResponse& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#unequip-asset-to-character-by-id
    * Unequip an asset from the specified character.
    *
    * @param CharacterId - ID of the character to unequip an asset from.
    * @param InstanceId - the asset's instance_id that is returned from the inventory and loadout calls.
    * @param AssetVariationId - the asset_variation_id.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
	static void UnEquipAssetToCharacterById(int CharacterId, int AssetId, int AssetVariationId, const FLootLockerCharacterDefaultResponse& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#get-current-loadout-to-default-character
    * Getting the current loadout will return an array of assets that the user currently has equipped.
    *
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
	static void GetCurrentLoadoutToDefaultCharacter(const FLootLockerCharacterLoadoutResponse& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#get-other-players-loadout-to-default-character
    * This method will return the exact same response as the GetCharacterLoadout, except that it will be for another player.
    *
    * @param OtherPlayerId - other player's ID.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
	static void GetOtherPlayersCurrentLoadoutToDefaultCharacter(const FString& OtherPlayerId, const FLootLockerCharacterLoadoutResponse& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#get-equippable-contexts-to-default-character
    * Get the contexts that the player's default character can equip.
    *
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
	static void GetEquipableContextsToDefaultCharacter(const FContextDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#get-equippable-contexts-by-character-id
    * Get the contexts that the specified player's default character can equip.
    *
    * @param OtherPlayerId - other player's ID.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
	static void GetEquipableContextsByCharacterId(const FString& OtherCharacterId, const FContextDelegate& OnCompletedRequest);
    
    //==================================================
    //Persistent Storage
    //==================================================
    
    /**
    * https://docs.lootlocker.io/game-api/#get-entire-persistent-storage
    * This call returns all key/value pairs on record for the current player, and can thus be slow if you create many.
    *
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void GetEntirePersistentStorage(const FPersistentStorageItemsResponseDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#get-a-single-key-from-persistent-storage
    * Get Key/Value pair from the player's persistent storage.
    *
    * @param Key - key of the key/value pair.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void GetItemFromPersistentStorage(const FString& Key, const FPersistentStorageItemResponseDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#updating-creating-key-value-pairs
    * Create/Update key/value pair(s).
    *
    * @param Items - array of items to be created/updated.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void AddItemsToPersistentStorage(const TArray<FPersistentStorageItem>& Items, const FPersistentStorageItemsResponseDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#deleting-a-key-value-pair
    * Delete a key/value pair.
    *
    * @param Key - key of a key/value pair.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void DeleteItemFromPersistentStorage(const FString& Key, const FPersistentStorageItemsResponseDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#getting-other-players-public-key-value-pairs
    * Read another players public key/value storage.
    *
    * @param PlayerId - players id or their public UID.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void GetPlayerPersistentStorage(const FString& PlayerId, const FPersistentStorageItemsResponseDelegate& OnCompletedRequest);
    
    //==================================================
    //Assets
    //==================================================
    
    /**
    * https://docs.lootlocker.io/game-api/#getting-contexts
    * Get all the contexts the game has.
    *
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void GetContexts(const FContextDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#getting-asset-list
    * Get all assets in a paginated form.
    *
    * @param OnCompletedRequest - callback to be invoked with the server response.
    * @param StartFromIndex - index of the item to start from.
    * @param ItemsCount - number of items to receive (50-200).
    * @param AssetFilter - optional filter.
    * @param IncludeUGC - whether to include UGC Assets.
    */
    static void GetAssets(const FAssetsResponseDelegate& OnCompletedRequest, int StartFromIndex = 0, int ItemsCount = 50, EAssetFilter AssetFilter = EAssetFilter::None, bool IncludeUGC = false);
    
    /**
    * https://docs.lootlocker.io/game-api/#getting-assets-by-ids
    * Retrieve only specific Assets by their ID's.
    *
    * @param AssetIds - array of the asset ID's to be fetched.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void GetAssetsByIds(const TArray<int>& AssetIds, const FAssetsResponseDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#getting-asset-bone-information
    * This call will return you all the default bones.
    * If a binding overrides anything on a bone, it will be returned along with the binding.
    *
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void GetAssetBones(const FAssetBonesResponseDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#listing-favourite-assets
    * This call will simply list the current players favourite assets.
    *
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void GetFavouriteAssetIndices(const FGetFavouriteAssetIndicesResponseDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#adding-favourite-assets
    * Add an asset to the list of favourites.
    *
    * @param AssetId - asset ID to be added.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void AddAssetToFavourites(int AssetId, const FGetFavouriteAssetIndicesResponseDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#removing-favourite-assets
    * Remove an asset from the list of favourites.
    *
    * @param AssetId - asset ID to be removed.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void RemoveAssetFromFavourites(int AssetId, const FGetFavouriteAssetIndicesResponseDelegate& OnCompletedRequest);
    
    //==================================================
    //Asset Instances
    //==================================================
    
    /**
    * https://docs.lootlocker.io/game-api/#getting-all-key-value-pairs-to-an-instance
    * Get all key/value pairs for an asset instance.
    *
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void GetAllKeyValuePairsForAssetInstance(const FAssetInstanceStorageItemsResponseDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#getting-all-key-value-pairs-to-an-instance
    * Get all key/value pairs for an asset instance.
    *
    * @param AssetInstanceId - asset instance ID.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void GetAllKeyValuePairsToAnInstanceForAssetInstance(int AssetInstanceId, const FAssetInstanceStorageItemsResponseDelegate& OnCompletedRequest);

    /**
    * https://docs.lootlocker.io/game-api/#getting-a-key-value-pair-by-id
    * Get a key/value pair for an asset instance.
    *
    * @param AssetInstanceId - asset instance ID.
    * @param StorageItemId - ID of the key/value pair.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void GetAKeyValuePairByIdForAssetInstance(int AssetInstanceId, int StorageItemId, const FAssetInstanceStorageItemsResponseDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#creating-a-key-value-pair
    * Create a key/value pair for an asset instance.
    *
    * @param AssetInstanceId - asset instance ID.
    * @param Item - key/value pair.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void CreateAKeyValuePairForAssetInstance(int AssetInstanceId, const FAssetInstanceStorageItem& Item, const FAssetInstanceStorageItemsResponseDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#updating-one-or-more-key-value-pairs
    * Update key/value pairs for an asset instance.
    *
    * @param AssetInstanceId - asset instance ID.
    * @param Items - key/value pairs.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void UpdateOneOrMoreKeyValuePairForAssetInstance(int AssetInstanceId, const TArray<FAssetInstanceStorageItem>& Items, const FAssetInstanceStorageItemsResponseDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#updating-a-key-value-pair-by-id
    * Update a key/value pair for an asset instance.
    *
    * @param AssetInstanceId - asset instance ID.
    * @param StorageItemId - key/value pair ID.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void UpdateAKeyValuePairByIdForAssetInstance(int AssetInstanceId, int StorageItemId, const FAssetInstanceStorageItem Item, const FAssetInstanceStorageItemsResponseDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#delete-a-key-value-pair
    * Delete a key/value pair for an asset instance.
    *
    * @param AssetInstanceId - asset instance ID.
    * @param StorageItemId - key/value pair ID.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void DeleteAKeyValuePairByIdForAssetInstance(int AssetInstanceId, int StorageItemId, const FAssetInstanceStorageItemsResponseDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#inspect-a-loot-box
    * Asset instances with the type set to loot box can be inspected, to see what assets the player might possibly get when opening them.
    *
    * @param AssetInstanceId - asset instance ID.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void InspectLootBox(int AssetInstanceId, const FLootBoxContentResponseDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#open-a-loot-box
    * Asset instances with the type set to loot box can be opened, using this endpoint.
    * Once you call this endpoint, the Loot Box will be removed from the players inventory, and a new asset will be added to the inventory,
    * with the acquisition_source set to grant_loot_box. You will be asked to check the grant notifications to see which asset was granted.
    *
    * @param AssetInstanceId - asset instance ID.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void OpenLootBox(int AssetInstanceId, const FOpenLootBoxResponseDelegate& OnCompletedRequest);
    
    //==================================================
    //User Generated Content
    //==================================================
    
    /**
    * https://docs.lootlocker.io/game-api/#creating-an-asset-candidate
    * Create an asset candidate.
    *
    * @param AsssetCandidate - asset candidate data.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void CreateAssetCandidate(const FAssetCandidate& AsssetCandidate, const FCreateAssetCandidateResponseDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#updating-an-asset-candidate
    * Update an asset candidate.
    *
    * @param AssetCandidateId - ID of the asset candidate.
    * @param AsssetCandidate - asset candidate data.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void UpdateAssetCandidate(int AssetCandidateId, const FAssetCandidate& AsssetCandidate, const FAssetCandidateResponseDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#deleting-an-asset-candidate
    * Delete an asset candidate.
    *
    * @param AssetCandidateId - ID of the asset candidate.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void DeleteAssetCandidate(int AssetCandidateId, const FResponseCallback& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#listing-asset-candidates
    * Get all asset candidates.
    *
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void GetAllAssetCandidates(const FAssetCandidatesResponseDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#getting-a-single-asset-candidate
    * Get an asset candidate.
    *
    * @param AssetCandidateId - ID of the asset candidate.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void GetAssetCandidate(int AssetCandidateId, const FAssetCandidateResponseDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#adding-files-to-asset-candidates
    * Add a file to an asset candidate.
    *
    * @param AssetCandidateId - ID of the asset candidate.
    * @param FilePath - full absolute path to a file.
    * @param FilePurpose - purpose of the file.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void AddFileToAssetCandidate(int AssetCandidateId, const FString& FilePath, EAssetFilePurpose FilePurpose, const FResponseCallback& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#removing-files-from-an-asset-candidate
    * Remove a file from an asset candidate.
    *
    * @param AssetCandidateId - ID of the asset candidate.
    * @param FileId - ID of the file.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void DeleteFileFromAssetCandidate(int AssetCandidateId, int FileId, const FResponseCallback& OnCompletedRequest);
    
    //==================================================
    //Missions
    //==================================================
    
    /**
    * https://docs.lootlocker.io/game-api/#getting-all-missions
    * Get all missions.
    *
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void GetAllMissions(const FMissionsResponseDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#getting-a-single-mission
    * Get a mission.
    *
    * @param MissionId - mission ID.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void GetMission(int MissionId, const FMissionResponseDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#starting-mission
    * Start a mission.
    *
    * @param MissionId - mission ID.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void StartMission(int MissionId, const FStartMissionResponseDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#finishing-mission
    * Finish a mission.
    *
    * @param MissionId - mission ID.
    * @param MissionData - mission completion data.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void FinishMission(int MissionId, const FFinishMissionData& MissionData, const FFinishMissionResponseDelegate& OnCompletedRequest);
    
    //==================================================
    //Maps
    //==================================================
    
    /**
    * https://docs.lootlocker.io/game-api/#getting-all-maps
    * Get maps data.
    *
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void GetMaps(const FGetMapsResponseDelegate& OnCompletedRequest);
    
    //==================================================
    //Purchases
    //==================================================
    
    /**
    * https://docs.lootlocker.io/game-api/#purchase-call
    * Sending a request to this endpoint with asset information, will facilitate a purchase.
    * If your game uses soft currency, it will check the players account balance and grant the assets to the player if there is coverage.
    * If there is no coverage, an error will be returned.
    *
    * @param PurchaseData - data about the assets to be purchased.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void PurchaseAssets(const TArray<FAssetPurchaseData>& PurchaseData, const FPurchaseResponseDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#android-in-app-purchases
    * Platform-specific purchase call for Android.
    *
    * @param PurchaseData - data about the assets to be purchased.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void PurchaseAssetsAndroid(const TArray<FAndroidAssetPurchaseData>& PurchaseData, const FPurchaseResponseDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#ios-in-app-purchases
    * Platform-specific purchase call for iOS.
    *
    * @param PurchaseData - data about the assets to be purchased.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void PurchaseAssetsIOS(const TArray<FVerifyPurchaseIosData>& PurchaseData, const FPurchaseResponseDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#polling-order-status
    * This call will let you know the current status of an order.
    * If you get a response that is considered final, you should issue a call to the player inventory endpoint if you're in a context where the inventory might change.
    *
    * @param PurchaseId - ID of the purchase order.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void PollingOrderStatus(int PurchaseId, const FPurchaseStatusResponseDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#activating-a-rental-asset
    * Once you have purchased a rental asset, you need to activate the rental for it to become available for the player. This endpoint achieves that.
    *
    * @param AssetId - ID of the asset.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void ActivateRentalAsset(int AssetId, const FActivateRentalAssetResponseDelegate& OnCompletedRequest);
    
    //==================================================
    //Trigger Events
    //==================================================
    
    /**
    * https://docs.lootlocker.io/game-api/#triggering-an-event
    * Trigger an event.
    *
    * @param Event - data of the event to be triggered.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void TriggerEvent(const FTriggerEvent& Event, const FTriggerEventResponseDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#listing-triggered-trigger-events
    * This endpoint lists the triggers that a player have already completed.
    *
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void GetTriggeredEvents(const FTriggersResponseDelegate& OnCompletedRequest);
    
    //==================================================
    //Collectables
    //==================================================
    
    /**
    * https://docs.lootlocker.io/game-api/#getting-collectables
    * This endpoint will return all the collectables a game has set up. It will hold a set of Collectables, with Groups inside which in turn contain Items.
    *
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void GetAllCollectables(const FCollectablesResponseDelegate& OnCompletedRequest);
    
    /**
    * https://docs.lootlocker.io/game-api/#collecting-an-item
    * Collecting an Item is done by calling this endpoint with a payload equal to the slug of the Item.
    * The slug is a combination of the name of the Collectable, the Group and the Item. Simply concatenate them with a . as a seperator.
    *
    * @param Item - the slug is a combination of the name of the Collectable, the Group and the Item. Simply concatenate them with a . as a seperator.
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void CollectItem(const FCollectItemPayload& Item, const FCollectablesResponseDelegate& OnCompletedRequest);
    
    //==================================================
    //Messages
    //==================================================
    
    /**
    * https://docs.lootlocker.io/game-api/#get-messages
    * Get all messages for a player.
    *
    * @param OnCompletedRequest - callback to be invoked with the server response.
    */
    static void GetMessages(const FMessagesResponseDelegate& OnCompletedRequest);
};
