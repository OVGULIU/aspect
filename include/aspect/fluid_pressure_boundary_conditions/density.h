/*
  Copyright (C) 2015 - 2016 by the authors of the ASPECT code.

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
     * The fluid pressure gradient can either be set to
     * $\rho_s \textbf{g}$ (solid density times gravity) or to
     * $\rho_f \textbf{g}$ (fluid density times gravity).
     *
     * @ingroup FluidPressureBoundaryConditions
     */
    template <int dim>
    class Density : public Interface<dim>, public SimulatorAccess<dim>
    {
      public:
        /**
         * @copydoc Interface::fluid_pressure
         */
        virtual
        void fluid_pressure_gradient (
          const types::boundary_id boundary_indicator,
          const MaterialModel::MaterialModelInputs<dim> &material_model_inputs,
          const MaterialModel::MaterialModelOutputs<dim> &material_model_outputs,
          std::vector<Tensor<1,dim> > &output
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

      private:
        /**
         * Identify which density to use to compute the fluid pressure
         * gradient at the model boundary.
         */
        struct DensityFormulation
        {
          enum Kind
          {
            solid_density,
            fluid_density
          };
        };

        typename DensityFormulation::Kind density_formulation;
    };
  }
}


#endif
