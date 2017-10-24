# Short Adaptivity and Transient Demonstration
=====

This was built based on Example `ex05` from MOOSE to show a quick demonstration of how to add adaptivity and transient analysis (and a mixture of both) to a simulation.

You will find the input files under `problems` and a presentation that talks about mesh adaptivity and transient analysis in `presentation`.

In addition, Cubit was used to generate the geometry for this demonstration.  You can find the Cubit journal file and resulting Exodus file under `geom`.

The input files are as follows:
 - `01_steady.i`: Just the simple steady state solution of a coupled convection diffusion problem
 - `02_steady_adapt.i`: Adding in some mesh adaptivity with a number of adaptive steps to get a better solution to the steady state problem
 - `03_transient.i`: Switching to a `Transient` Executioner and adding a time derivative
 - `04_transient_adapt.i`: Adding a little bit of adaptivity.  But notice that the solution is not good for the first few timesteps because of the coarse mesh
 - `05_transient_adapt_with_uniform.i`: Add some initial uniform refinement to capture the first few stpes well.  Allow coarsening to remove that initial refinement.
