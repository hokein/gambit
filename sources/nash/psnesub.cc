//
// FILE: psnesub.cc -- Enumerating of pure mixed strategies
//
// $Id$
//

#include "psnesub.h"
#include "nfgpure.h"

void efgEnumPureNfgSolve::SolveSubgame(const FullEfg &E, const EFSupport &sup,
				       gList<BehavSolution> &solns,
				       gStatus &p_status)
{
  Nfg *N = MakeReducedNfg(sup);
  NFSupport support(*N);
  ViewNormal(*N, support);

  gList<MixedSolution> solutions;
  nfgEnumPure solver;
  solver.SetStopAfter(m_stopAfter);
  solutions = solver.Solve(support, p_status);

  for (int i = 1; i <= solutions.Length(); i++)  {
    MixedProfile<gNumber> profile(*solutions[i].Profile());
    solns.Append(BehavProfile<gNumber>(profile));
  }

  delete N;
}

efgEnumPureNfgSolve::efgEnumPureNfgSolve(int p_stopAfter)
  : SubgameSolver(0), m_stopAfter(p_stopAfter)
{ }

efgEnumPureNfgSolve::~efgEnumPureNfgSolve()   { }


