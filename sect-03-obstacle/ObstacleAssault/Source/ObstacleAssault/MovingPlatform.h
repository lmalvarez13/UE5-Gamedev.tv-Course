// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BillboardComponent.h"
#include "Components/StaticMeshComponent.h"
#include "MovingPlatform.generated.h"



UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/* Properties & Macros
	* UPROPERTY(EditAnywhere/VisibleAnywhere) -> Allows you to edit/see the variable from inside the Editor
	* 
	
	*/
	UPROPERTY(VisibleAnywhere);
	bool hasReachedEndPoint = false;

	/* Adding Billboard by using the Constructor */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UBillboardComponent> StartPosition;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UBillboardComponent> EndPosition;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> PlatformMesh;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components",
			meta = (ClampMin = "1.0"))
	FVector PlatformSize = FVector(
		500.0f,
		400.0f,
		30.0f
	);


};
