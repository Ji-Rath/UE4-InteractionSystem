#pragma once

#include "CoreMinimal.h"
#include "Inventory/InventoryComponent.h"
#include "PlayerEquipComponent.generated.h"

class USpringArmComponent;
class AInteractable;
class UInventoryComponent;

UCLASS(Blueprintable)
class INTERACTIONSYSTEM_API UPlayerEquipComponent : public UActorComponent
{
	GENERATED_BODY()
	
protected:
	void BeginPlay() override;

public:
	UPlayerEquipComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Equip the item that is in the slot */
	UFUNCTION(BlueprintCallable)
	void EquipItem(UItemData* Item);

	/** Unequip any currently equipped items */
	UFUNCTION(BlueprintCallable)
	void UnequipItem();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	UItemData* GetEquippedItem() const;

	UFUNCTION(BlueprintCallable)
	void DropEquippedItem();

private:
	UPROPERTY(EditDefaultsOnly)
	FComponentReference ItemAttachParent;

	UItemData* EquippedItem = nullptr;

	UPROPERTY(EditDefaultsOnly)
	float ItemUnequipOffset = -25.f;

	UPROPERTY(EditDefaultsOnly)
	float InitialSpringArmOffset = 0.f;

	UPROPERTY(EditDefaultsOnly)
	float ThrowImpulse = 500.f;

	USpringArmComponent* ItemAttachSpring;

	UInventoryComponent* InventoryCompRef;

	TArray<FInventoryContents> Inventory;

	/** Called when there is an inventory update */
	UFUNCTION()
	void UpdateEquip(bool bAdded);

	UFUNCTION()
	void ItemInteract(AInteractable* Interactable);

};

