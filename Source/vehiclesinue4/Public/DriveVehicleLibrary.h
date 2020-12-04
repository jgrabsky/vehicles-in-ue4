// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DriveVehicleLibrary.generated.h"

class UWheeledVehicleMovementComponent;
class UPhysicalMaterial;

/**
 * 
 */
UCLASS()
class VEHICLESINUE4_API UDriveVehicleLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category="vehiclesinue4")
		static TArray<UPhysicalMaterial*> GetPhysicalMaterialsUnderTires(UWheeledVehicleMovementComponent* VehicleMovement);

	UFUNCTION(BlueprintCallable, Category = "vehiclesinue4")
		static float GetMaxSuspensionForce(UWheeledVehicleMovementComponent* VehicleMovement);

	UFUNCTION(BlueprintCallable, Category = "vehiclesinue4")
		static bool CheckSlipThreshold(UWheeledVehicleMovementComponent* VehicleMovement, float LongSlipThreshold, float LatSlipThreshold);
};
