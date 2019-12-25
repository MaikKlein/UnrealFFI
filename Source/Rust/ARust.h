// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ARust.generated.h"

UCLASS()
class UNREALRUST_API AARust : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AARust();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void* dllHandle = nullptr;
	static void logFromUnreal(const char* log, unsigned int foo) {
        FString name = FString(log);
		UE_LOG(LogTemp, Warning, TEXT("Logging called from Rust! %s"), *name);
	}
};
