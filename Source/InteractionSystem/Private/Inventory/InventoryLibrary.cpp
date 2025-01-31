﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/InventoryLibrary.h"

#include "Interaction/ItemData.h"
#include "Inventory/InventoryInfo.h"

bool UInventoryLibrary::IsA(const FInventoryContents& Item, UItemInformation* Source)
{
	return Item.Item.Get().ItemInformation->IsA(Source->StaticClass());
}

bool UInventoryLibrary::IsValid(FItemHandle& ItemHandle)
{
	return ItemHandle.IsValid();
}
