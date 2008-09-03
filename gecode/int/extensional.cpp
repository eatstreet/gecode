/* -*- mode: C++; c-basic-offset: 2; indent-tabs-mode: nil -*- */
/*
 *  Main authors:
 *     Mikael Lagerkvist <lagerkvist@gecode.org>
 *     Christian Schulte <schulte@gecode.org>
 *
 *  Copyright:
 *     Mikael Lagerkvist, 2007
 *     Christian Schulte, 2004
 *
 *  Last modified:
 *     $Date$ by $Author$
 *     $Revision$
 *
 *  This file is part of Gecode, the generic constraint
 *  development environment:
 *     http://www.gecode.org
 *
 *  Permission is hereby granted, free of charge, to any person obtaining
 *  a copy of this software and associated documentation files (the
 *  "Software"), to deal in the Software without restriction, including
 *  without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to
 *  permit persons to whom the Software is furnished to do so, subject to
 *  the following conditions:
 *
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 *  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 *  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 *  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include "gecode/int/extensional.hh"

namespace Gecode {

  void
  extensional(Space& home, const IntVarArgs& x, DFA dfa, 
              IntConLevel, PropKind) {
    using namespace Int;
    if (x.same(home))
      throw ArgumentSame("Int::extensional");
    if (home.failed()) return;
    ViewArray<IntView> xv(home,x);
    GECODE_ES_FAIL(home,Extensional::post_lgp<IntView>(home,xv,dfa));
  }

  void
  extensional(Space& home, const BoolVarArgs& x, DFA dfa, 
              IntConLevel, PropKind) {
    using namespace Int;
    if (x.same(home))
      throw ArgumentSame("Int::extensional");
    if (home.failed()) return;
    ViewArray<BoolView> xv(home,x);
    GECODE_ES_FAIL(home,Extensional::post_lgp<BoolView>(home,xv,dfa));
  }

  void
  extensional(Space& home, const IntVarArgs& x, const TupleSet& t, 
              IntConLevel, PropKind pk) {
    using namespace Int;
    if (!t.finalized())
      const_cast<TupleSet&>(t).finalize();
    if (t.arity() != x.size())
      throw ArgumentSizeMismatch("Int::extensional");
    if (home.failed()) return;

    // Construct view array
    ViewArray<IntView> xv(home,x);
    switch (pk) {
    case PK_SPEED:
      GECODE_ES_FAIL(home,(Extensional::Incremental<IntView>
                           ::post(home,xv,t)));
      break;
    default:
      if (x.same(home)) {
        GECODE_ES_FAIL(home,(Extensional::Basic<IntView,true>
                             ::post(home,xv,t)));
      } else {
        GECODE_ES_FAIL(home,(Extensional::Basic<IntView,false>
                             ::post(home,xv,t)));
      }
      break;
    }
  }

  void
  extensional(Space& home, const BoolVarArgs& x, const TupleSet& t, 
              IntConLevel, PropKind pk) {
    using namespace Int;
    if (!t.finalized())
      const_cast<TupleSet&>(t).finalize();
    if (t.arity() != x.size())
      throw ArgumentSizeMismatch("Int::extensional");
    if (home.failed()) return;

    // Construct view array
    ViewArray<BoolView> xv(home,x);
    switch (pk) {
    case PK_SPEED:
      GECODE_ES_FAIL(home,(Extensional::Incremental<BoolView>
                           ::post(home,xv,t)));
      break;
    default:
      if (x.same(home)) {
        GECODE_ES_FAIL(home,(Extensional::Basic<BoolView,true>
                             ::post(home,xv,t)));
      } else {
        GECODE_ES_FAIL(home,(Extensional::Basic<BoolView,false>
                             ::post(home,xv,t)));
      }
      break;
    }
  }

  GECODE_REGISTER3(Int::Extensional::LayeredGraph
                   <Int::IntView,unsigned char,short int>);
  GECODE_REGISTER3(Int::Extensional::LayeredGraph
                   <Int::IntView,unsigned short int,short int>);
  GECODE_REGISTER3(Int::Extensional::LayeredGraph
                   <Int::IntView,unsigned int,short int>);
  GECODE_REGISTER3(Int::Extensional::LayeredGraph
                   <Int::IntView,unsigned long int,short int>);
  GECODE_REGISTER3(Int::Extensional::LayeredGraph
                   <Int::IntView,unsigned char,int>);
  GECODE_REGISTER3(Int::Extensional::LayeredGraph
                   <Int::IntView,unsigned short int,int>);
  GECODE_REGISTER3(Int::Extensional::LayeredGraph
                   <Int::IntView,unsigned int,int>);
  GECODE_REGISTER3(Int::Extensional::LayeredGraph
                   <Int::IntView,unsigned long int,int>);
  GECODE_REGISTER3(Int::Extensional::LayeredGraph
                   <Int::IntView,unsigned char,long int>);
  GECODE_REGISTER3(Int::Extensional::LayeredGraph
                   <Int::IntView,unsigned short int,long int>);
  GECODE_REGISTER3(Int::Extensional::LayeredGraph
                   <Int::IntView,unsigned int,long int>);
  GECODE_REGISTER3(Int::Extensional::LayeredGraph
                   <Int::IntView,unsigned long int,long int>);

  GECODE_REGISTER3(Int::Extensional::LayeredGraph
                   <Int::BoolView,unsigned char,short int>);
  GECODE_REGISTER3(Int::Extensional::LayeredGraph
                   <Int::BoolView,unsigned short int,short int>);
  GECODE_REGISTER3(Int::Extensional::LayeredGraph
                   <Int::BoolView,unsigned int,short int>);
  GECODE_REGISTER3(Int::Extensional::LayeredGraph
                   <Int::BoolView,unsigned long int,short int>);
  GECODE_REGISTER3(Int::Extensional::LayeredGraph
                   <Int::BoolView,unsigned char,int>);
  GECODE_REGISTER3(Int::Extensional::LayeredGraph
                   <Int::BoolView,unsigned short int,int>);
  GECODE_REGISTER3(Int::Extensional::LayeredGraph
                   <Int::BoolView,unsigned int,int>);
  GECODE_REGISTER3(Int::Extensional::LayeredGraph
                   <Int::BoolView,unsigned long int,int>);
  GECODE_REGISTER3(Int::Extensional::LayeredGraph
                   <Int::BoolView,unsigned char,long int>);
  GECODE_REGISTER3(Int::Extensional::LayeredGraph
                   <Int::BoolView,unsigned short int,long int>);
  GECODE_REGISTER3(Int::Extensional::LayeredGraph
                   <Int::BoolView,unsigned int,long int>);
  GECODE_REGISTER3(Int::Extensional::LayeredGraph
                   <Int::BoolView,unsigned long int,long int>);


  GECODE_REGISTER2(Int::Extensional::Basic<Int::IntView,true>);
  GECODE_REGISTER2(Int::Extensional::Basic<Int::IntView,false>);
  GECODE_REGISTER1(Int::Extensional::Incremental<Int::IntView>);

  GECODE_REGISTER2(Int::Extensional::Basic<Int::BoolView,true>);
  GECODE_REGISTER2(Int::Extensional::Basic<Int::BoolView,false>);
  GECODE_REGISTER1(Int::Extensional::Incremental<Int::BoolView>);

}

// STATISTICS: int-post
