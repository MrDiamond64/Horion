#include "XpCommand.h"

XpCommand::XpCommand() : IMCCommand("xp", "Add experience to your player", "xp <amount>L") {
}

XpCommand::~XpCommand() {
}

bool XpCommand::execute(std::vector<std::string>* args) {
	return false;
}
