// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class HELLO_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();
	FVector2D start;			// 이동 전 좌표
	FVector2D currentLocation;	// 이동 후 좌표
	int32 step();				// 0 or 1 반환하는 함수. x,y 좌표에 각각 더해짐
	void move(int);				// int를 매개변수로 받아 이동횟수 조절 가능
	float totDist = 0;			// 총 이동거리
	int32 evCnt = 0;			// 총 이벤트 발생횟수
	void createEvent();			// 이벤트 발생함수
	float distance(FVector2D, FVector2D);	// 좌표간 거리 구하는 함수

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
