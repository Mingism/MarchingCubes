#pragma once

#include "World.h"
#include "ChunkActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VoxelWorld.generated.h"


UCLASS()
class PROCEDURAL_API AVoxelWorld : public AActor
{
	GENERATED_BODY()

public:
	AVoxelWorld();
	~AVoxelWorld();

	virtual void Tick(float DeltaTime) override;
	virtual bool CanEditChange(const UProperty* InProperty) const override;

	void Update();

	UFUNCTION(BlueprintCallable, Category = "Voxel")
		void Add(FVector hitPoint);
	UFUNCTION(BlueprintCallable, Category = "Voxel")
		void Remove(FVector hitPoint);

protected:
	virtual void BeginPlay() override;

private:
	void CreateWorld();
	void DeleteWorld();
	AChunkActor* GetChunk(int x, int y, int z);

	UPROPERTY(EditAnywhere, Category = Voxel)
		int Size;
	UPROPERTY(EditAnywhere, Category = Voxel)
		UMaterialInterface* material;
	bool bNotCreated;
	World* world;
	TArray<AChunkActor*> chunks;
};
