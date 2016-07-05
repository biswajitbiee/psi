
// Class library implementation of PSS-tool build-model callback
#include "api/IModel.h"
#include "classlib/TypeRegistry.h"
#include "classlib/Elaborator.h"
#include "classlib/Action.h"

using namespace psi;

static Elaborator elab;

void psi_build_model(psi_api::IModel *model) {
    elab.elaborate(TypeRegistry::global(), model);
}

#include <map>

static std::map<psshandle_t,Action*> handle2action_map;

void psi_post_solve(psshandle_t handle) {
    // Currently only Action supported, need to generalize to structs..
    Action* act_inst = 0; // = lookup_cached_instances(handle);
    if (act_inst == 0) {
        Action* act_type = elab.getActionType(handle);
        if (act_type  == 0) {
            // some kind of error?
        }
        act_inst = static_cast<Action*>(act_type->createInstance(handle));
        //cache_instance(act_inst,handle);
      act_inst->post_solve();
    }
}
