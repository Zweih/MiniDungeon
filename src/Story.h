#pragma once

typedef struct Location Location;
typedef struct MonsterDef MonsterDef;

typedef void (*StoryInitializeFunction)(void);

typedef struct Story
{
	int gameNumber;
	int gameDataVersion;
	int numberOfLocations;
	Location *locationList;
	int numberOfMonsters;
	MonsterDef *monsterList;
//	Dialog *dialogList; // NYI
	StoryInitializeFunction initializeStory;
} Story;

typedef struct StoryState
{
	bool needsSaving;
	int currentLocationIndex;
	int currentLocationDuration;
	int currentPathDestination; // The global index for the Location to go to when the current path finishes.
	int mostRecentMonster;
} StoryState;

void RegisterStory(const Story *story, StoryState *storyState);

//Location *GetLocationByIndex(int index);
MonsterDef *GetMonsterByIndex(int index);

int GetCurrentBackgroundImage(void);
MonsterDef *GetRandomMonster(void);
MonsterDef *GetFixedMonster(int index);
int GetCurrentLocationEncounterChance(void);
int GetCurrentBaseLevel(void);

const char *GetCurrentLocationName(void);
void IncrementCurrentDuration(void);
int GetCurrentDuration(void);
int GetCurrentLocationLength(void);

bool IsCurrentLocationPath(void);

// Debug function
void FollowFirstPath(void);

void SetNewLocation(int index);
int GetCurrentDestinationIndex(void);

// Takes an index into the adjacent locations array, and returns a global location index
int GetCurrentAdjacentLocationIndex(int index);

void InitializeCurrentStory(void);