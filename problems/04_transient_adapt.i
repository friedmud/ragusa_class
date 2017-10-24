[Mesh]
  file = ../geom/2d_circle_hole.e
[]

[Variables]
  [./convected]
    order = FIRST
    family = LAGRANGE
  [../]
  [./diffused]
    order = FIRST
    family = LAGRANGE
  [../]
[]

[Kernels]
  [./example_diff]
    type = ExampleCoefDiffusion
    variable = convected
    coef = 0.125
  [../]
  [./conv]
    type = ExampleConvection
    variable = convected
    some_variable = 'diffused'
  [../]
  [./diff]
    type = Diffusion
    variable = diffused
  [../]
  [./td]
    type = TimeDerivative
    variable = convected
  [../]
[]

[BCs]
  # convected=0 on all vertical sides except the right (x-max)
  [./cylinder_convected]
    type = DirichletBC
    variable = convected
    boundary = 'inside'
    value = 1
  [../]
  [./exterior_convected]
    type = DirichletBC
    variable = convected
    boundary = 'left top bottom'
    value = 0
  [../]
  [./left_diffused]
    type = DirichletBC
    variable = diffused
    boundary = 'left'
    value = 0
  [../]
  [./right_diffused]
    type = DirichletBC
    variable = diffused
    boundary = 'right'
    value = 10
  [../]
[]

[Executioner]
  type = Transient
  num_steps = 100
  dt = 0.001
[]

[Adaptivity]
  marker = errorfrac
  max_h_level = 3
  [./Indicators]
    [./error]
      type = GradientJumpIndicator
      variable = convected
      outputs = 'none'
      scale_by_flux_faces = true
    [../]
  [../]
  [./Markers]
    [./errorfrac]
      type = ErrorFractionMarker
      refine = 0.5
      indicator = error
      outputs = 'none'
    [../]
  [../]
[]

[Outputs]
  execute_on = 'timestep_end'
  exodus = true
[]

[Preconditioning]
  [./SMP_asm]
    type = SMP
    petsc_options_value = 'asm 2 3'
    off_diag_column = 'diffused'
    off_diag_row = 'convected'
    petsc_options_iname = '-pc_type -pc_asm_overlap -sub_pc_factor_levels'
  [../]
[]
