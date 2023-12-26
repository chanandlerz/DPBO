dpbo_final_project_sources = [
  'main.vala',
  'login.vala',
  'application.vala',
  'register.vala',
  'forum.vala',
  'create.vala',
]

dpbo_final_project_deps = [
  dependency('gtk4'),
]

gnome = import('gnome')

dpbo_final_project_sources += gnome.compile_resources('dpbo_final_project-resources',
  'dpbo_final_project.gresource.xml',
  c_name: 'dpbo_final_project'
)

executable('dpbo-final-project', dpbo_final_project_sources,
  vala_args: '--target-glib=2.50',  dependencies: dpbo_final_project_deps,
  install: true,
)
