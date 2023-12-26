public class Application : Gtk.Application {
    public Application () {
        Object (
            application_id: "org.example.login_page", flags: ApplicationFlags.FLAGS_NONE
        );
    }

    protected override void activate () {
        var window = new Create.Window (this);
        window.show ();

        //  var register = new Register.Window(this);
        //  register.show();

        add_window(window);
        //  add_window (register);
    }
}