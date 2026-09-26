// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/BillboardComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "MovingPlatform.h"


// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootComponent =
		CreateDefaultSubobject<USceneComponent>(
			TEXT("Root")
		);

	PlatformMesh =
		CreateDefaultSubobject<UStaticMeshComponent>(
			TEXT("Static Mesh")
		);

	StartPosition =
		CreateDefaultSubobject<UBillboardComponent>(
			TEXT("Start")
		);

	EndPosition =
		CreateDefaultSubobject<UBillboardComponent>(
			TEXT("End")
		);

	SetRootComponent(RootComponent);

	StartPosition->SetupAttachment(RootComponent);
	(*EndPosition).SetupAttachment(RootComponent);


	// Platform Mesh setup 
	PlatformMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		CubeMesh(
			TEXT("/Engine/BasicShapes/Cube.Cube")
		);

	if (CubeMesh.Succeeded()) { 
		PlatformMesh->SetStaticMesh(CubeMesh.Object);
		PlatformMesh->SetRelativeScale3D(PlatformSize / 100.0);
	}

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	/* FVector Example */
	/*
	FVector newVector = FVector(13.0f, 2.5f, 3.65f);
	UE_LOG(LogTemp, Display, TEXT("This are the coordinates ! %f %f %f"),
		newVector.X, newVector.Y, newVector.Z);
	*/

	const bool bStartAttached =
		StartPosition->GetAttachParent() == RootComponent;

	const bool bEndAttached =
		EndPosition->GetAttachParent() == RootComponent;

	UE_LOG(
		LogTemp,
		Warning,
		TEXT("StartPoint attached to Root: %s"),
		bStartAttached ? TEXT("YES") : TEXT("NO")
	);

	UE_LOG(
		LogTemp,
		Warning,
		TEXT("EndPoint attached to Root: %s"),
		bEndAttached ? TEXT("YES") : TEXT("NO")
	);

	/* Platform positioning */

	FVector initialPosition = StartPosition->GetRelativeLocation();
	PlatformMesh->SetRelativeLocation(initialPosition);

	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

