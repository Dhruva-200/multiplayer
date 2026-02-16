//CPP->

IOnlineSubsystem* OnlineSubsystem=IOnlineSubsystem::Get(); //I means an interface -> which is a rule book
if(OnlineSubsystem){                                        // || OnlineSubsytem is a pointer that stores memory of real online subsytem object 
	OnlineSessionInterface = OnlineSubsystem->GetSessionInterface();	// We use a pointer because Unreal already created the object,
	if (GEngine) {                                                   //  and interfaces can’t be created — we only store the address to use it.
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, FString::Printf(TEXT("Online Subsystem: %s"), *OnlineSubsystem->GetSubsystemName().ToString()));
	}
}

//HEADER->

public:
	TSharedPtr<class IOnlineSession, ESPMode::ThreadSafe> OnlineSessionInterface;
