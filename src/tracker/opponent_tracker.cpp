#include "roboteam_world/tracker/opponent_tracker.h"
#include <algorithm>

namespace rtt {
    
OpponentTracker::~OpponentTracker() {
    for (auto module : modules) {
        delete module;
    }
}    
    
void OpponentTracker::update(const World& world) {
    for (TrackerModule* module : modules) {
        module->update(world);
    }
}

bool OpponentTracker::add_module(TrackerModule* module) {
    if (std::find(modules.begin(), modules.end(), module) != modules.end()) {
        return false;
    }
    modules.push_back(module);
    return true;
}

bool OpponentTracker::has_module(const TrackerModule& module) const {
    return has_module(module.name());
}

bool OpponentTracker::has_module(const std::string& name) const {
    for (const TrackerModule* module : modules) {
        if (module->name() == name) {
            return true;
        }
    }
    return false;
}

const TrackerModule* OpponentTracker::get_module(const std::string& name) const {
    for (const TrackerModule* module : modules) {
        if (name == module->name()) {
            return module;
        }
    }
    return nullptr;
}

bool OpponentTracker::remove_module(const TrackerModule& module) {
    return remove_module(module.name());
}

bool OpponentTracker::remove_module(const std::string& name) {
    for (TrackerModule* module : modules) {
        if (module->name() == name) {
            modules.remove(module);
            return true;
        }
    }
    return false;
}

}