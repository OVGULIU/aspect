/*
  Copyright (C) 2011 - 2015 by the authors of the ASPECT code.

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


#ifndef _aspect_postprocess_visualization_compositional_vector_h
#define _aspect_postprocess_visualization_compositional_vector_h

#include <aspect/postprocess/visualization.h>
#include <aspect/simulator_access.h>

#include <deal.II/numerics/data_postprocessor.h>


namespace aspect
{
  namespace Postprocess
  {
    namespace VisualizationPostprocessors
    {
      /**
       * A class derived from DataPostprocessor that can output sets of dim
       * compositional fields as vectors.
       */
      template <int dim>
      class CompositionalVector
        : public DataPostprocessor<dim>,
          public SimulatorAccess<dim>,
          public Interface<dim>
      {
        public:
          CompositionalVector ();

          virtual
          std::vector<std::string>
          get_names () const;

          virtual
          std::vector<DataComponentInterpretation::DataComponentInterpretation>
          get_data_component_interpretation () const;

          virtual
          UpdateFlags
          get_needed_update_flags () const;

          virtual
          void
          compute_derived_quantities_vector (const std::vector<Vector<double> >              &solution_values,
                                             const std::vector<std::vector<Tensor<1,dim> > > &solution_gradients,
                                             const std::vector<std::vector<Tensor<2,dim> > > &solution_hessians,
                                             const std::vector<Point<dim> >                  &normals,
                                             const std::vector<Point<dim> >                  &evaluation_points,
                                             std::vector<Vector<double> >                    &computed_quantities) const;

          static
          void
          declare_parameters (ParameterHandler &prm);

          virtual
          void
          parse_parameters (ParameterHandler &prm);

        private:
          /* Names of vector fields. */
          std::vector<std::string> vector_names;
          /*
           * Stores sets of compositional field indices to
           * be visualized together as vector fields.
           */
          std::vector<std::vector<unsigned int > > sets;
      };
    }
  }
}

#endif
