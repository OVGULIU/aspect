/*
  Copyright (C) 2013 by the authors of the ASPECT code.

  This file is part of ASPECT.

  ASPECT is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2, or (at your option)
  any later version.

  ASPECT is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with ASPECT; see the file doc/COPYING.  If not see
  <http://www.gnu.org/licenses/>.
*/


#ifndef __aspect__fluid_pressure_boundary_conditions_density_h
#define __aspect__fluid_pressure_boundary_conditions_density_h

#include <aspect/fluid_pressure_boundary_conditions/interface.h>
#include <aspect/simulator_access.h>


namespace aspect
{
  namespace FluidPressureBoundaryConditions
  {
    /**
     * A class that implements simple fluid pressure boundary conditions
     * based on the fluid or solid density from the material model.
     *
     * @ingroup FluidPressureBoundaryConditions
     */
    template <int dim>
    class Density : public Interface<dim>
    {
      public:
        /**
         * @copydoc Interface::fluid_pressure_gradient
         */
        virtual
        void fluid_pressure_gradient (
            const typename MaterialModel::MeltInterface<dim>::MaterialModelInputs &material_model_inputs,
            const typename MaterialModel::MeltInterface<dim>::MaterialModelOutputs &material_model_outputs,
            std::vector<double> & output
            ) const;

        /**
         * Declare the parameters this class takes through input files.
         */
        static
        void
        declare_parameters (ParameterHandler &prm);

        /**
         * Read the parameters this class declares from the parameter file.
         */
        virtual
        void
        parse_parameters (ParameterHandler &prm);

        /**
         * @copydoc Interface::initialilze()
         */
        virtual void initialize ();

      private:
        /**
         * If true, the solid density is used.
         */
        bool include_rho_s;
        /**
         * If true, the fluid density is used.
         */
        bool include_rho_f;
    };
  }
}


#endif
