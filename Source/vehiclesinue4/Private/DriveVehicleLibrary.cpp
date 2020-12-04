// Fill out your copyright notice in the Description page of Project Settings.


#include "DriveVehicleLibrary.h"
#include "WheeledVehicleMovementComponent.h"

TArray<UPhysicalMaterial*> UDriveVehicleLibrary::GetPhysicalMaterialsUnderTires(UWheeledVehicleMovementComponent* VehicleMovement)
{
	TArray<UPhysicalMaterial*> Mats;

	if (VehicleMovement)
	{
		for (UVehicleWheel* Wheel : VehicleMovement->Wheels)
		{
			Mats.Emplace(Wheel->GetContactSurfaceMaterial());
		}
	}

	return Mats;
}

float UDriveVehicleLibrary::GetMaxSuspensionForce(UWheeledVehicleMovementComponent* VehicleMovement)
{
	if (VehicleMovement)
	{
		return VehicleMovement->GetMaxSpringForce();
	}
	return 0.0f;
}

bool UDriveVehicleLibrary::CheckSlipThreshold(UWheeledVehicleMovementComponent* VehicleMovement, float LongSlipThreshold, float LatSlipThreshold)
{
	if (VehicleMovement)
	{
		float Long = FMath::Clamp<float>(LongSlipThreshold, 0, 1);
		float Lat = FMath::Clamp<float>(LatSlipThreshold, 0, 1);

		return VehicleMovement->CheckSlipThreshold(Long, Lat);
	}
	return false;
}
