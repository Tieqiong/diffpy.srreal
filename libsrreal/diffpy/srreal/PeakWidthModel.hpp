/*****************************************************************************
*
* diffpy.srreal     by DANSE Diffraction group
*                   Simon J. L. Billinge
*                   (c) 2009 Trustees of the Columbia University
*                   in the City of New York.  All rights reserved.
*
* File coded by:    Christopher Farrow, Pavol Juhas
*
* See AUTHORS.txt for a list of people who contributed.
* See LICENSE.txt for license information.
*
******************************************************************************
*
* class PeakWidthModel -- base class for calculation of peak widths.
*     The calculate function takes a BondGenerator instance and
*     returns full width at half maximum, based on peak model parameters
*     and anisotropic displacement parameters of atoms in the pair.
*
* $Id$
*
*****************************************************************************/

#ifndef PEAKWIDTHMODEL_HPP_INCLUDED
#define PEAKWIDTHMODEL_HPP_INCLUDED

#include <string>
#include <map>

namespace diffpy {
namespace srreal {

class BaseBondGenerator;

class PeakWidthModel
{
    public:

        // constructors
        virtual PeakWidthModel* create() const = 0;
        virtual PeakWidthModel* copy() const = 0;
        virtual ~PeakWidthModel()  { }

        // methods
        virtual const std::string& type() const = 0;
        virtual double calculate(const BaseBondGenerator&) const = 0;

        // comparison with derived classes
        virtual bool operator==(const PeakWidthModel&) const = 0;

    private:

        // class method for registration
        friend PeakWidthModel* createPeakWidthModel(const std::string&);
        friend bool registerPeakWidthModel(const PeakWidthModel&);
        // class method for registration
        typedef std::map<std::string, const PeakWidthModel*> RegistryType;
        static RegistryType& getRegistry();
};

// Factory functions for Peak Width Models -----------------------------------

PeakWidthModel* createPeakWidthModel(const std::string& tp);
bool registerPeakWidthModel(const PeakWidthModel&);

}   // namespace srreal
}   // namespace diffpy

#endif  // PEAKWIDTHMODEL_HPP_INCLUDED
