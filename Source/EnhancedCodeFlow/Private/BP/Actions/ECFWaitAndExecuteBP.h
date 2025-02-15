// Copyright (c) 2022 Damian Nowakowski. All rights reserved.

#pragma once

#include "../ECFActionBP.h"
#include "ECFWaitAndExecuteBP.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnECFWaitAndExecuteBPEvent, class UECFWaitAndExecuteBP*, Action);

UCLASS()
class ENHANCEDCODEFLOW_API UECFWaitAndExecuteBP : public UECFActionBP
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable)
	FOnECFWaitAndExecuteBPEvent OnWait;

	UPROPERTY(BlueprintAssignable)
	FOnECFWaitAndExecuteBPEvent OnExecute;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", AdvancedDisplay = "Settings", ToolTip = "Waits until specific conditions are made and then execute code.\nUse Action's 'Predicate' function to control it.", DisplayName = "ECF - Wait And Execute"), Category = "ECF")
	static UECFWaitAndExecuteBP* ECFWaitAndExecute(UObject* WorldContextObject, FECFActionSettings Settings, FECFHandleBP& Handle);

	UFUNCTION(BlueprintCallable, meta = (ToolTip = "Pass 'true' to this function in order to execute the 'Wait And Execute' Action."), Category = "ECF")
	void Predicate(bool bHasFinished);

protected:

	bool Proxy_HasFinished = false;
};
