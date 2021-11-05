// Copyright (c) 2021 LootLocker

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LootLockerSDKManager.h"

#include "DemoUserGeneratedContent.generated.h"

UCLASS()
class DEMOPROJECT_API ADemoUserGeneratedContent : public AActor
{
public:
    GENERATED_BODY()
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FLootLockerAssetCandidate2 AsssetCandidate;
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int AssetCandidateId;
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString FilePath;
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    ELootLockerAssetFilePurpose FilePurpose;
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int FileId;
    
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "LootLocker Demo | User Generated Content")
    void DemoCreateAssetCandidate();
    
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "LootLocker Demo | User Generated Content")
    void DemoUpdateAssetCandidate();
    
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "LootLocker Demo | User Generated Content")
    void DemoDeleteAssetCandidate();
    
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "LootLocker Demo | User Generated Content")
    void DemoGetAllAssetCandidates();
    
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "LootLocker Demo | User Generated Content")
    void DemoGetAssetCandidate();
    
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "LootLocker Demo | User Generated Content")
    void DemoAddFileToAssetCandidate();
    
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "LootLocker Demo | User Generated Content")
    void DemoDeleteFileFromAssetCandidate();
    
    void OnCreateAssetCandidateCompleted(FLootLockerCreateAssetCandidateResponse Response);
    void OnUpdateAssetCandidateCompleted(FLootLockerAssetCandidateResponse Response);
    void OnDeleteAssetCandidateCompleted(FLootLockerResponse Response);
    void OnGetAllAssetCandidatesCompleted(FLootLockerAssetCandidatesResponse Response);
    void OnGetAssetCandidateCompleted(FLootLockerAssetCandidateResponse Response);
    void OnAddFileToAssetCandidateCompleted(FLootLockerResponse Response);
    void OnDeleteFileFromAssetCandidateCompleted(FLootLockerResponse Response);
    
private:
    ULootLockerSDKManager* LootLockerManager;
};
