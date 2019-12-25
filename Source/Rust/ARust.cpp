// Fill out your copyright notice in the Description page of Project Settings.


#include "ARust.h"


typedef unsigned int(*_rustLog)(void* fp);

_rustLog m_rustLog;


// Sets default values
AARust::AARust()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void AARust::EndPlay(const EEndPlayReason::Type EndPlayReason) {
	UE_LOG(LogTemp, Warning, TEXT("HANDLE DESTORYED %i"), this->dllHandle);
    if(this->dllHandle != nullptr) {
	    FPlatformProcess::FreeDllHandle(this->dllHandle);
    }
    m_rustLog = nullptr;
}
// Called when the game starts or when spawned
void AARust::BeginPlay()
{
	Super::BeginPlay();
    FString filePath = *FPaths::ProjectDir() + FString("/librust.so");
    if(this->dllHandle != nullptr) {
	    FPlatformProcess::FreeDllHandle(this->dllHandle);
    }
	this->dllHandle = FPlatformProcess::GetDllHandle(*filePath);
	FString symbol = "rust_log";
	m_rustLog = (_rustLog)FPlatformProcess::GetDllExport(this->dllHandle, *symbol);
    SIZE_T dllAddr = (SIZE_T)this->dllHandle;
    SIZE_T logAddr = (SIZE_T)m_rustLog;
	UE_LOG(LogTemp, Warning, TEXT("DLL Address %i"), dllAddr);
	UE_LOG(LogTemp, Warning, TEXT("Log Address %i"), logAddr);
	if (m_rustLog != nullptr ) {
		unsigned int val = (m_rustLog)((void*)AARust::logFromUnreal);
		UE_LOG(LogTemp, Warning, TEXT("Value %i"), val);
	}
}

// Called every frame
void AARust::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


