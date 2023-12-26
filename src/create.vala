public class Create.Window : Gtk.ApplicationWindow {
    private Gtk.Box box_vertical;
    private Gtk.Box box_horizontal_user;
    private Gtk.Box box_horizontal_button;
    private Gtk.Image user_image;
    private Gtk.Entry description_entry;
    private Gtk.Button pickImage;
    private Gtk.Button post;

    public Window (Application app) {
        Object (
            application: app, default_height: 200, default_width: 300
        );
    }

    

    construct {
        this.title = "Create Post";

        box_vertical = new Gtk.Box (VERTICAL, 10);
        box_vertical.add_css_class ("verticalBox");
        box_horizontal_user = new Gtk.Box (HORIZONTAL, 10);
        box_horizontal_user.add_css_class ("userBox");
        box_horizontal_button = new Gtk.Box (HORIZONTAL, 10);
        box_horizontal_button.add_css_class ("buttonBox");
        user_image = new Gtk.Image.from_file ("/home/memories/Projects/dpbo-final-project/src/taku-morisaki.jpg");
        user_image.set_pixel_size (30);
        description_entry = new Gtk.Entry ();
        description_entry.add_css_class("description-entry");
        description_entry.set_size_request(200, 200);
        box_horizontal_user.append (user_image);
        box_horizontal_user.append (description_entry);
        box_horizontal_user.set_hexpand(true); 
        box_horizontal_user.set_halign(Gtk.Align.CENTER);

        pickImage = new Gtk.Button.from_icon_name ("image");
        post = new Gtk.Button.with_label ("Post");
        post.add_css_class("post-button");
        //  box_horizontal_button.append (pickImage);
        box_horizontal_button.append (post);
        box_horizontal_button.set_hexpand(true); 
        box_horizontal_button.set_halign(Gtk.Align.CENTER);

        box_vertical.append (box_horizontal_user);
        box_vertical.append (box_horizontal_button);

        this.set_child (box_vertical);



        var css_provider = new Gtk.CssProvider ();
        string path = "/home/nadia/Documents/vala/dpbo-final-project/src/style.css"; //absolute path


        //print("%d",(int) FileUtils.test (path, FileTest.EXISTS));  
        css_provider.load_from_path (path);
        Gtk.StyleContext.add_provider_for_display (Gdk.Display.get_default (), css_provider, Gtk.STYLE_PROVIDER_PRIORITY_USER);
        //label.add_css_class("text_label");
    }
}