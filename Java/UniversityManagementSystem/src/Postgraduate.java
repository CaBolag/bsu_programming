public class Postgraduate extends Student {
    private Academic supervisor;

    public Postgraduate(String login, String email) {
        super(login, email);
    }


    public Academic getSupervisor() {
        return supervisor;
    }

    public void setSupervisor(Academic supervisor) {
        this.supervisor = supervisor;
    }

    public String toString(){
        return super.toString()+
                "Supervisor: "+supervisor.getName()+"\n";
    }
}
