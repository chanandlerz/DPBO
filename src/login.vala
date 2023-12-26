public class MyApp.Window : Gtk.ApplicationWindow {
    private Gtk.Box box;
    private Gtk.Label username_label;
    private Gtk.Entry username_entry;
    private Gtk.Label password_label;
    private Gtk.Entry password_entry;
    private Gtk.Button login_button;

    public Window (Application app) {
        Object (
            application: app, default_height: 200, default_width: 300
        );
    }

    

    construct {
        this.title = "Login";

        box = new Gtk.Box (VERTICAL, 10);
        username_label = new Gtk.Label ("Username:");
        username_entry = new Gtk.Entry ();
        password_label = new Gtk.Label ("Password:");
        password_entry = new Gtk.Entry ();
        login_button = new Gtk.Button.with_label ("Login");

        box.append (username_label);
        box.append (username_entry);
        box.append (password_label);
        box.append (password_entry);
        box.append (login_button);


        login_button.clicked.connect (() => {
            //  print ("Username: %s\n", username_entry.text);
            //  print ("Password: %s\n", password_entry.text);
            var register_window = new Register.Window (application);
            register_window.show();
            this.hide ();
        });

        this.set_child (box);
    }
}