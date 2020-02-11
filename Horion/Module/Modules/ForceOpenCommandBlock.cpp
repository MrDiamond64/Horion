#include "ForceOpenCommandBlock.h"

ForceOpenCommandBlock::ForceOpenCommandBlock() : IModule(0x0, Category::EXPLOITS, "Open command blocks even if you are not operator") {
}

ForceOpenCommandBlock::~ForceOpenCommandBlock() {
}

const char* ForceOpenCommandBlock::getModuleName() {
	return ("ForceOpenCommandBlock");
}

void ForceOpenCommandBlock::onTick(C_GameMode* gm) {
	PointingStruct* pointingStruct = g_Data.getClientInstance()->getPointerStruct();
	C_Block* block = gm->player->region->getBlock(pointingStruct->block);
	if (pointingStruct->entityPtr != nullptr && pointingStruct->entityPtr->getEntityTypeId() == 100 && GameData::isRightClickDown() && GameData::canUseMoveKeys()) {
		__int64* id = pointingStruct->entityPtr->getUniqueId();
		g_Data.getLocalPlayer()->openCommandBlockMinecart(*id);
	} else if (block != nullptr && block->toLegacy()->blockId == 137 && GameData::isRightClickDown() && GameData::canUseMoveKeys()) {
		g_Data.getLocalPlayer()->openCommandBlock(pointingStruct->block);
	}
}