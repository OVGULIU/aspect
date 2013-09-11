/*
  Copyright (C) 2012 by the authors of the ASPECT code.

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
/*  $Id: density.h 1008 2012-05-09 18:46:44Z bangerth $  */

#ifndef __aspect__postprocess_visualization_surface_topography_h
#define __aspect__postprocess_visualization_surface_topography_h

#include <aspect/postprocess/visualization.h>
#include <aspect/simulator_access.h>


namespace aspect
{
  namespace Postprocess
  {
    namespace VisualizationPostprocessors
    {
      /**
       * A postprocessor that takes an output vector and
       * computes the surface topography at the surface
       * using the normal stresses.
       *
       * Normal stress is calculated in the middle of
       * each cell. Best accuracy with a laterally
       * homogeneous mesh refinement.
       *
       * @ingroup Postprocessing
       */
      template <int dim>
      class SurfaceTopography : public CellDataVectorCreator<dim>,
                                public SimulatorAccess<dim>
      {
        public:
          /**
           * Evaluate the solution for the surface topography.
           *
           * The function classes have to implement that want to output
           * cellwise data.
           * @return A pair of values with the following meaning:
           *   - The first element provides the name by which this
           *     data should be written to the output file.
           *   - The second element is a pointer to a vector with
           *     one element per active cell on the current processor.
           *     Elements corresponding to active cells that are either
           *     artificial or ghost cells (in deal.II language, see the
           *     deal.II glossary) will be ignored but must nevertheless
           *     exist in the returned vector. While implementations of this
           *     function must create this vector, ownership is taken over
           *     by the caller of this function and the caller will take
           *     care of destroying the vector pointed to.
           **/
          virtual
          std::pair<std::string, Vector<float> *>
          execute () const;
      };
    }
  }
}


#endif
