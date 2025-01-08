// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	start = FVector2D(0.0, 0.0);			// 각종 변수들 초기화
	currentLocation = FVector2D(0.0, 0.0);
	evCnt = 0;
	totDist = 0;
}

float AMyActor::distance(FVector2D a, FVector2D b) {
	float dx = a.X - b.X;
	float dy = a.Y - b.Y;
	return FMath::Sqrt(dx * dx + dy * dy);
}
int32 AMyActor::step() {
	return FMath::RandRange(0, 1);
}
void AMyActor::move(int movecount) {

	int count = 1;
	while (count <= movecount) {
		currentLocation.X = start.X + step();	// X,Y 좌표의 이동 거리 계산
		currentLocation.Y = start.Y + step();	//
		
		if (currentLocation.X == start.X && currentLocation.Y == start.Y) {		// 둘 다 0이 나왔을 경우 이동하지 않은 것으로 간주
			UE_LOG(LogTemp, Log, TEXT("당신은 잠시 휴식하기로 했다. 현재 좌표 : %f, %f "), currentLocation.X, currentLocation.Y);
		}																		
		else {																	// 이동 후 이동거리, 좌표 표시
			UE_LOG(LogTemp, Log, TEXT("%f 만큼 이동하였습니다. 현재 좌표 : %f, %f"), distance(currentLocation, start), currentLocation.X, currentLocation.Y);
			count++;
			int event = FMath::RandRange(0, 100);								// 이동 시에만 50% 확률로 이벤트 발생
			if (event < 50) {													// 이벤트 함수를 따로 빼서 관리
				UE_LOG(LogTemp, Log, TEXT("이벤트 발생!"));
				createEvent();
			}
		}
		totDist += distance(currentLocation, start);							// 이동 거리를 더하고
		start.X = currentLocation.X;											// 다음 루프를 위해 이동 후 좌표를 이동 전 좌표에 할당
		start.Y = currentLocation.Y;
		
	}
	UE_LOG(LogTemp, Log, TEXT("이동 종료. 총 이동 횟수 : %i 회 / 총 이동 거리 : %f / 이벤트 발생 횟수 : %i 회"), movecount, totDist, evCnt);
}
void AMyActor::createEvent() {
	int eventvalue = 0;
	eventvalue = FMath::RandRange(1, 3);
	switch (eventvalue)
	{
	case 1:
		UE_LOG(LogTemp, Log, TEXT("갑자기 하늘에서 비가 내리기 시작했다."));
		break;
	case 2:
		UE_LOG(LogTemp, Log, TEXT("갑자기 강한 바람이 몰아치기 시작했다."));
		break;
	case 3:
		UE_LOG(LogTemp, Log, TEXT("갑자기 태양이 거세게 타오르기 시작했다."));
		break;
	}
	evCnt++;
}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Log, TEXT("좌표 초기화. 현재 좌표 : ( %f , %f )"), start.X, start.Y);

	move(15);
	
}

void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

