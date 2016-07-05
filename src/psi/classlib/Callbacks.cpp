
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

void psi_post_solve(psshandle_t psshandle) {
    Action* act_inst = 0; // = lookup_cached_instances(psshandle);
    if (act_inst == 0) {
        Action* act_type = elab.getActionType(psshandle);
        if (act_type  == 0) {
            // some kind of error?
        }
        act_inst = act_type; // my_action_type->createInstance(psshandle);
        act_inst->m_psshandle = psshandle;
        //cache_instance(act_inst,psshandle);
      act_inst->post_solve();
    }
}
