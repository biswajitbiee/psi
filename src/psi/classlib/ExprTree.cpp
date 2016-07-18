#include "ExprTree.h"
#include "ExprCoreList.h"
#include <algorithm>
#include <iterator>

namespace psi {
  ExprTree::ExprTree() : Expr(new ExprCoreList()) 
  {
    setOp(Expr::Tree);
  }

  ExprTree::ExprTree(const Expr& expr) : Expr(new ExprCoreList())
  {
    setOp(Expr::Tree);

    ExprCoreList* plist = static_cast<ExprCoreList*>(m_core.ptr());
    plist->getExprList().emplace_back(expr.getCore());
  }
      
  ExprTree::ExprTree(std::initializer_list<Expr> exprlist) : Expr(new ExprCoreList()) 
  {
    setOp(Expr::Tree);

    ExprCoreList* plist = static_cast<ExprCoreList*>(m_core.ptr());

    auto& list = plist->getExprList();
    std::transform(exprlist.begin(), exprlist.end(), std::back_inserter(list),
                    [](const Expr& expr) { return expr.getCore(); });
  }

  void ExprTree::add(const Expr& item)
  {
    ExprCoreList* plist = static_cast<ExprCoreList*>(m_core.ptr());
    plist->getExprList().emplace_back(item.getCore());
  }

/*  void ExprTree::add(const SharedPtr<Type>& ptr)
  {
    ExprCoreList* plist = static_cast<ExprCoreList*>(m_core.ptr());
  
    //plist->getExprList().emplace_back(ptr);
  }*/
}
