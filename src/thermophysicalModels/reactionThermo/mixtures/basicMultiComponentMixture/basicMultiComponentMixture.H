/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 1991-2010 OpenCFD Ltd.
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::basicMultiComponentMixture

Description
    combustion mixture

SourceFiles
    basicMultiComponentMixture.C

\*---------------------------------------------------------------------------*/

#ifndef basicMultiComponentMixture_H
#define basicMultiComponentMixture_H

#include "volFields.H"
#include "PtrList.H"
#include "speciesTable.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                 Class basicMultiComponentMixture Declaration
\*---------------------------------------------------------------------------*/

class basicMultiComponentMixture
{

protected:

    // Protected data

        //- Table of specie names
        speciesTable species_;

        //- Species mass fractions
        PtrList<volScalarField> Y_;


public:

    // Constructors

        //- Construct from dictionary and mesh
        basicMultiComponentMixture
        (
            const dictionary&,
            const wordList& specieNames,
            const fvMesh&
        );


    //- Destructor
    virtual ~basicMultiComponentMixture()
    {}


    // Member functions

        //- Return the table of species
        const speciesTable& species() const
        {
            return species_;
        }

        //- Return the mass-fraction fields
        inline PtrList<volScalarField>& Y();

        //- Return the const mass-fraction fields
        inline const PtrList<volScalarField>& Y() const;

        //- Return the mass-fraction field for a specie given by index
        inline volScalarField& Y(const label i);

        //- Return the const mass-fraction field for a specie given by index
        inline const volScalarField& Y(const label i) const;

        //- Return the mass-fraction field for a specie given by name
        inline volScalarField& Y(const word& specieName);

        //- Return the const mass-fraction field for a specie given by name
        inline const volScalarField& Y(const word& specieName) const;

        //- Does the mixture include this specie?
        inline bool contains(const word& specieName) const;

        inline scalar fres(const scalar ft, const scalar stoicRatio) const;

        inline tmp<volScalarField> fres
        (
            const volScalarField& ft,
            const dimensionedScalar& stoicRatio
        ) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "basicMultiComponentMixtureI.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
