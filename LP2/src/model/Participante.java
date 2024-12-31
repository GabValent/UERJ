package model;

public class Participante {

	private String nome;
	private String matricula;
	private String curso;
	private String evento;
	
	
	public Participante() {}
	
	public Participante(String nome, String matricula, String curso, String evento) {
		this.nome = nome;
		this.matricula = matricula;
		this.curso = curso;
		this.evento = evento;
	}

	public String getNome() {
		return nome;
	}


	public void setNome(String nome) {
		this.nome = nome;
	}


	public String getMatricula() {
		return matricula;
	}


	public void setMatricula(String matricula) {
		this.matricula = matricula;
	}


	public String getCurso() {
		return curso;
	}


	public void setCurso(String curso) {
		this.curso = curso;
	}


	public String getEvento() {
		return evento;
	}


	public void setEvento(String evento) {
		this.evento = evento;
	}
}
