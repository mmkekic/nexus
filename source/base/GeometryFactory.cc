// ----------------------------------------------------------------------------
//  $Id$
//
//  Author : <justo.martin-albo@ific.uv.es>    
//  Created: 13 March 2013
//
//  Copyright (c) 2013 NEXT Collaboration. All rights reserved.
// ----------------------------------------------------------------------------

#include "GeometryFactory.h"

#include "BaseGeometry.h"
#include <G4GenericMessenger.hh>


using namespace nexus;


GeometryFactory::GeometryFactory(): _msg(0)
{
  _msg = new G4GenericMessenger(this, "/Geometry/");
  _msg->DeclareProperty("RegisterGeometry", _name, "");
}


GeometryFactory::~GeometryFactory()
{
  delete _msg;
}


//////////////////////////////////////////////////////////////////////

#include "XeSphere.h"
#include "CylindricChamber.h"
#include "Next1EL.h"
#include "Next100.h"
#include "NextNewOpticalGeometry.h"
#include "NextNew.h"
#include "MagBox.h"
#include "PetalX.h"
#include "PetalX2.h"
#include "PetalX4.h"
#include "FullRing.h"
#include "PetaloTrapAlone.h"
#include "PMT_QE_setup.h"
#include "Lab.h"

BaseGeometry* GeometryFactory::CreateGeometry() const
{
  BaseGeometry* p = 0;

  if      (_name == "XE_SPHERE") p = new XeSphere();

  else if (_name == "CYLINDRIC_CHAMBER") p = new CylindricChamber();
  
  else if (_name == "NEXT1_EL") p = new Next1EL();

  else if (_name == "NEXT100") p = new Next100();

  else if (_name == "OPTICAL_GEOMETRY") p = new NextNewOpticalGeometry();

  else if (_name == "NEXT_NEW") p = new NextNew();

  else if (_name == "MAG_BOX") p = new MagBox();

  else if (_name == "PMT_QE_SETUP") p = new PMT_QE_setup();
  
  else if (_name == "PETALX") p = new PetalX();

  else if (_name == "PETALX2") p = new PetalX2();

  else if (_name == "PETALX4") p = new PetalX4();

  else if (_name == "FULLRING") p = new FullRing();
  
  else if (_name == "TRAP") p = new PetaloTrapAlone();

  else if (_name == "2MODULES") p = new Lab();

  else {
    G4String err = "The user selected an unknown geometry: " + _name;
    G4Exception("CreateGeometry", "[BaseGeometry]", FatalException, err);
  }

  return p;
}


