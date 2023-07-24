#include "includes.h"

void CustomStyleImGui(ImGuiStyle* style)
{
	ImVec4* colors = style->Colors;
	colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.00f, 0.50f, 0.00f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.50f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.50f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.50f);
	colors[ImGuiCol_Border] = ImVec4(0.00f, 1.00f, 0.00f, 0.50f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.50f, 0.00f, 0.50f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.00f, 0.50f, 0.00f, 0.50f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.00f, 0.50f, 0.00f, 0.50f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.00f, 0.50f, 0.00f, 0.50f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.50f, 0.00f, 0.50f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.00f, 0.50f, 0.00f, 0.50f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.50f, 0.00f, 0.50f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.00f, 0.50f, 0.00f, 0.50f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.00f, 0.50f, 0.00f, 0.50f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.00f, 1.00f, 0.00f, 0.50f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.00f, 1.00f, 0.00f, 0.50f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.00f, 1.00f, 0.00f, 0.50f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.00f, 1.00f, 0.00f, 0.50f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.00f, 1.00f, 0.00f, 0.50f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.00f, 1.00f, 0.00f, 0.50f);
	colors[ImGuiCol_Button] = ImVec4(0.00f, 1.00f, 0.00f, 0.50f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.00f, 1.00f, 0.00f, 0.50f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.00f, 1.00f, 0.00f, 0.50f);
	colors[ImGuiCol_Header] = ImVec4(0.00f, 1.00f, 0.00f, 0.50f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 1.00f, 0.00f, 0.50f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.00f, 1.00f, 0.00f, 0.50f);
	colors[ImGuiCol_Separator] = ImVec4(0.00f, 1.00f, 0.00f, 0.50f);
}