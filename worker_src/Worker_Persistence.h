#pragma once
#include "../src/MiniDungeon.h"

#include <pebble_worker.h>

bool LoadWorkerData(void);
bool GetWorkerCanLaunch(void);
void SetWorkerCanLaunch(bool enable);
bool GetClosedInBattle(void);
void SetClosedInBattle(bool enable);
