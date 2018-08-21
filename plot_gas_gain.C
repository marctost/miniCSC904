#include "snippet.C"
#include <vector>
#include "root_tools.h"
#include "plotting_functions.h"

int graph_section(TString which_chamber, int zoom, PlotterLines voltage, vector<PlotterLines> run);

void plot_gas_gain(TString which_chamber) {
    ExcelSheet test(which_chamber+"/"+"analysis_page_gasGain.csv");

    // This is the important bit! The first value (test) refers to the excel sheet above. The second number is
    // the row you start on. The second number is the lowest row you go to. Doesn't have to be exact,
    // we have a function that makes things perfect. The 3rd number is the column that you're pulling. The
    // last number is the number of adjacent columns you're using. Make sure to remember that things start
    // at zero!! So be careful.
   
    vector<PlotterLines> run;
    
    PlotterLines voltage(test, 1, 12, 0, 1);
    PlotterLines run_0(test, 1, 12, 1, 1);
    PlotterLines run_1(test, 1, 12, 2, 1);
    PlotterLines run_2(test, 1, 12, 3, 1);
    PlotterLines run_3(test, 1, 12, 4, 1);
    PlotterLines run_4(test, 1, 12, 5, 1);
    PlotterLines run_5(test, 1, 12, 6, 1);
    PlotterLines run_6(test, 1, 12, 7, 1);
    PlotterLines run_7(test, 1, 12, 8, 1);
    PlotterLines run_8(test, 1, 12, 9, 1);
    PlotterLines run_9(test, 1, 12, 10, 1);
    PlotterLines run_10(test, 1, 12, 11, 1);
    
    run.push_back(run_0); run.push_back(run_1); run.push_back(run_2); run.push_back(run_3); run.push_back(run_4); run.push_back(run_5); run.push_back(run_6); run.push_back(run_7); run.push_back(run_8); run.push_back(run_9); run.push_back(run_10);
    
    //Make plots
    graph_section(which_chamber, 0, voltage, run); //no zoom
    graph_section(which_chamber, 1, voltage, run); //zoom around 3.6 kV
}



int graph_section(TString which_chamber, int zoom, PlotterLines voltage, vector<PlotterLines> run){
    
    TString title = "Absolute Gas Gain: Irr. Layer";
    
	//Just some styling stuff
	gROOT->SetBatch(true);
	gStyle->SetOptStat(2210);
	gStyle->SetTitleAlign(23);


    vector<TGraph*> graph;
    TCanvas *canvas = make_canvas();
    TLegend *legend = make_legend();

    // This is where the graphs are made. Given argument voltage, which run to do, the color and the transparency of the color. Formatting is done here too.
    graph.push_back(make_graph_gg(voltage, run[0], kRed, 0.1));
    graph.push_back(make_graph_gg(voltage, run[1], kRed, 0.2));
    graph.push_back(make_graph_gg(voltage, run[2], kRed, 0.3));
    graph.push_back(make_graph_gg(voltage, run[3], kRed, 0.4));
    graph.push_back(make_graph_gg(voltage, run[4], kRed, 0.5));
    graph.push_back(make_graph_gg(voltage, run[5], kRed+2, 1));
//    graph.push_back(make_graph_gg(voltage, run[6], kRed, 0.7));
//    graph.push_back(make_graph_gg(voltage, run[7], kRed, 0.1));
//    graph.push_back(make_graph_gg(voltage, run[8], kRed, 0.1));
//    graph.push_back(make_graph_gg(voltage, run[9], kRed, 0.1));
//    graph.push_back(make_graph_gg(voltage, run[10], kRed, 0.1));
    
    
    // Label the legend by hand
    legend->AddEntry(graph[0], "Run 0, 0 mC/cm");
    legend->AddEntry(graph[1], "Run 1, 18 mC/cm");
    legend->AddEntry(graph[2], "Run 2, 26 mC/cm");
    legend->AddEntry(graph[3], "Run 3, 65 mC/cm");
    legend->AddEntry(graph[4], "Run 4, 125 mC/cm");
    legend->AddEntry(graph[5], "Run 5, 180 mC/cm");
    //legend->AddEntry(graph[6], "Run 6, ? mC/cm");
    //legend->AddEntry(graph[7], "Run 7, ? mC/cm");
    //legend->AddEntry(graph[8], "Run 8, ? mC/cm");
    //legend->AddEntry(graph[9], "Run 9, ? mC/cm");
    //legend->AddEntry(graph[10], "Run 10, ? mC/cm");
    
    
    // Make a multigraph to put all the stuff into and draw all at once.
    TMultiGraph *mg = new TMultiGraph();
    
    mg->Add(graph[0]);
    mg->Add(graph[1]);
    mg->Add(graph[2]);
    mg->Add(graph[3]);
    mg->Add(graph[4]);
    mg->Add(graph[5]);
    //mg->Add(graph[6]);
    //mg->Add(graph[7]);
    //mg->Add(graph[8]);
    //mg->Add(graph[9]);
    //mg->Add(graph[10]);
    
    
    // title
    mg->SetTitle(title);
    
    //Set the plot to log on the y-axis
    canvas->SetLogy();
    mg->Draw("ALP");
    canvas->SetLogy();
    
    //  label axis
    mg->GetXaxis()->SetTitle("Voltage (kV)");
    mg->GetYaxis()->SetTitle("Gas Gain");
    
    if (zoom==0){
        mg->GetXaxis()->SetRangeUser(0.2,3.8);
        mg->GetYaxis()->SetRangeUser(0.5, 500000);
        TLine *line = new TLine(3.6, 0, 3.6, 500000);
        line->SetLineColor(kPink-9);
        line->SetLineWidth(2.0);
        line->Draw();
    }
    else{
        mg->GetXaxis()->SetRangeUser(3.25,3.70);
        mg->GetYaxis()->SetRangeUser(10000, 200000);
        TLine *line = new TLine(3.6, 0, 3.6, 200000);
        line->SetLineColor(kPink-9);
        line->SetLineWidth(2.0);
        line->Draw();
    }
    
	legend->Draw("SAME");
    
    

    // Save plot
    system("mkdir -p "+which_chamber+"/"+"Plots/");
	TString saveWhere = which_chamber+"/"+"Plots/gas_gain"+to_string(zoom)+".pdf";
	canvas->Update();
//    canvas->SaveAs(saveWhere.c_str());
    canvas->SaveAs(saveWhere);
	delete canvas;

	return 0;
}
