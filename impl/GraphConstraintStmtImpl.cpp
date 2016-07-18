#include "GraphConstraintStmtImpl.h"

namespace psi {
  IGraphStmt::GraphStmtType GraphConstraintStmtImpl::getStmtType() const
  {
    return IGraphStmt::GraphStmt_Constraint;
  }

  void GraphConstraintStmtImpl::add(IConstraint* c)
  {
    m_constraints.emplace_back(c);
  }

  const std::vector<IConstraint*>& GraphConstraintStmtImpl::getConstraints() const
  {
    return m_constraints;
  }
}
