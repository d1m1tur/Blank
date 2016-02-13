using UnityEngine;
using System.Collections;
using System.Diagnostics;

public class Example : MonoBehaviour 
{
	void Start()
	{

	}

	void Awake()
	{
		Process myProcess = new Process();

		myProcess.StartInfo.Arguments = "resources\\code.jpg";
		myProcess.StartInfo.FileName = "background.exe";
		myProcess.StartInfo.WorkingDirectory = "C:\\Users\\Mitko\\Desktop\\background";
		myProcess.Start();   
		  
	}

	void Update()
	{

	}
}