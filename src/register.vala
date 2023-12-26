public class Register.Window : Gtk.ApplicationWindow {
    private Gtk.Box box;
    private Gtk.Label username_label;
    private Gtk.Entry username_entry;
    private Gtk.Label password_label;
    private Gtk.Entry password_entry;
    private Gtk.Label email_label;
    private Gtk.Entry email_entry;
    private Gtk.Label notelp_label;
    private Gtk.Entry notelp_entry;
    private Gtk.Button register_button;

    public Window (Gtk.Application app) {
        Object (application: app, default_height: 200, default_width: 300);
    }

    construct {
        this.title = "Register";

        box = new Gtk.Box (VERTICAL, 10);
        username_label = new Gtk.Label ("Username:");
        username_label.set_justify (LEFT);
        username_entry = new Gtk.Entry ();
        password_label = new Gtk.Label ("Password:");
        password_entry = new Gtk.Entry ();
        email_label = new Gtk.Label ("Email");
        email_entry = new Gtk.Entry ();
        notelp_label = new Gtk.Label ("Nomor Telepon");
        notelp_entry = new Gtk.Entry ();
        register_button = new Gtk.Button.with_label ("Register");

        box.append (username_label);
        box.append (username_entry);
        box.append (email_label);
        box.append (email_entry);
        box.append (notelp_label);
        box.append (notelp_entry);
        box.append (password_label);
        box.append (password_entry);
        box.append (register_button);

        register_button.clicked.connect (() => {
            //  print ("Username: %s\n", username_entry.text);
            //  print ("Password: %s\n", password_entry.text);
            var forum_window = new Forum.Window (application);
            forum_window.show();
            this.hide ();
        });

        this.set_child (box);
    }
}