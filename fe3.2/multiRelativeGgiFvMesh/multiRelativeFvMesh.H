/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | foam-extend: Open Source CFD
   \\    /   O peration     |
    \\  /    A nd           | For copyright notice see file Copyright
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of foam-extend.

    foam-extend is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation, either version 3 of the License, or (at your
    option) any later version.

    foam-extend is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with foam-extend.  If not, see <http://www.gnu.org/licenses/>.

Class
    multiRelativeFvMesh

Description
    Mixer mesh with multiple rotors.

Author
    Hrvoje Jasak, Wikki Ltd.  All rights reserved.

SourceFiles
    multiRelativeFvMesh.C

\*---------------------------------------------------------------------------*/

#ifndef multiRelativeFvMesh_H
#define multiRelativeFvMesh_H

#include "topoChangerFvMesh.H"
#include "relativeRotor.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                   Class multiRelativeFvMesh Declaration
\*---------------------------------------------------------------------------*/

class multiRelativeFvMesh
:
    public topoChangerFvMesh
{
    // Private data

        //- Motion dictionary
        dictionary dict_;

        //- Mixer rotors
        PtrList<relativeRotor> rotors_;

        //- Attach-detach action
        Switch attachDetach_;


    // Private Member Functions

        //- Disallow default bitwise copy construct
        multiRelativeFvMesh(const multiRelativeFvMesh&);

        //- Disallow default bitwise assignment
        void operator=(const multiRelativeFvMesh&);


        //- Add mixer rotor zones and modifiers
        void addZonesAndModifiers();

        //- Return true if any of the rotors uses a topological change
        bool useTopoSliding() const;

        //- Check that rotors using a topological change are in sync
        void checkRotors() const;

        //- Return true if sliding interface are attached
        bool attached() const;


public:

    //- Runtime type information
    TypeName("multiRelativeFvMesh");


    // Constructors

        //- Construct from IOobject
        explicit multiRelativeFvMesh(const IOobject& io);


    // Destructor

        virtual ~multiRelativeFvMesh();


    // Member Functions

        //- Update the mesh for both mesh motion and topology change
        virtual bool update();
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
