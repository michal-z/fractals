#define NULL ((void *)0)
#ifdef _DEBUG
#define assert(expression) if (!(expression)) { __debugbreak(); }
#else
#define assert(expression)
#endif
#define restrict __restrict
typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned int U32;
typedef unsigned long long U64;
typedef char S8;
typedef short S16;
typedef int S32;
typedef int B32;
typedef long long S64;
typedef float F32;
typedef double F64;

#define VHR(r) if ((r) < 0) { assert(0); }
#define COMRELEASE(o) if ((o)) { IUnknown_Release((o)); (o) = NULL; }

#define PM_REMOVE 0x0001
#define WM_QUIT 0x0012
#define WM_DESTROY 0x0002
#define WM_KEYDOWN 0x0100
#define VK_ESCAPE 0x001b
#define VK_CONTROL 0x11
#define WS_OVERLAPPED 0x00000000L
#define WS_VISIBLE 0x10000000L
#define WS_CAPTION 0x00C00000L
#define WS_SYSMENU 0x00080000L
#define WS_MINIMIZEBOX 0x00020000L
#define CW_USEDEFAULT ((U32)0x80000000)
#define MAKEINTRESOURCE(i) ((char *)((U64)((U16)(i))))
#define IDC_ARROW MAKEINTRESOURCE(32512)
#define PFD_TYPE_RGBA 0
#define PFD_DOUBLEBUFFER 0x00000001
#define PFD_DRAW_TO_WINDOW 0x00000004
#define PFD_SUPPORT_OPENGL 0x00000020
#define GENERIC_READ 0x80000000
#define OPEN_EXISTING 3
#define MEM_COMMIT 0x1000
#define MEM_RESERVE 0x2000
#define MEM_RELEASE 0x8000
#define PAGE_READWRITE 0x04
#define INFINITE 0xFFFFFFFF
#define STANDARD_RIGHTS_REQUIRED 0x000F0000L
#define SYNCHRONIZE 0x00100000L
#define EVENT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)

typedef struct POINT { S32 x, y; } POINT;
typedef struct MSG { void *hwnd; U32 message; U64 wParam; S64 lParam; U32 time; POINT pt; } MSG;
typedef struct GUID { U32 Data1; U16 Data2; U16 Data3; U8 Data4[8]; } GUID;
typedef struct SECURITY_ATTRIBUTES { U32 nLength; void *lpSecurityDescriptor; S32 bInheritHandle; } SECURITY_ATTRIBUTES;
typedef struct RECT { S32 left; S32 top; S32 right; S32 bottom; } RECT;
typedef struct WNDCLASS { U32 style; void *lpfnWndProc; S32 cbClsExtra; S32 cbWndExtra; void *hInstance; void *hIcon; void *hCursor; void *hbrBackground; const char *lpszMenuName; const char *lpszClassName; } WNDCLASS;

void *__stdcall LoadLibraryA(const char *);
void *__stdcall GetProcAddress(void *, const char *);

S32 _fltused;

static void (__stdcall *OutputDebugString)(const char *);
static B32 (__stdcall *QueryPerformanceCounter)(S64 *);
static B32 (__stdcall *QueryPerformanceFrequency)(S64 *);
static void *(__stdcall *VirtualAlloc)(void *, U64, U32, U32);
static B32 (__stdcall *VirtualFree)(void *, U64, U32);
static void (__stdcall *ExitProcess)(U32);
static void *(__stdcall *CreateFile)(const char *, U32, U32, SECURITY_ATTRIBUTES *, U32, U32, void *);
static B32 (__stdcall *ReadFile)(void *, void *, U32, U32 *, void *);
static U32 (__stdcall *GetFileSize)(void *, U32 *);
static B32 (__stdcall *CloseHandle)(void *);
static void *(__stdcall *GetModuleHandle)(const char *);
static void (__stdcall *Sleep)(U32);
static void *(__stdcall *HeapAlloc)(void *, U32, U64);
static B32 (__stdcall *HeapFree)(void *, U32, void *);
static void *(__stdcall *HeapReAlloc)(void *, U32, void *, U64);
static void *(__stdcall *GetProcessHeap)(void);
static void *(__stdcall *CreateEventEx)(SECURITY_ATTRIBUTES *, const char *, U32, U32);
static U32 (__stdcall *WaitForSingleObject)(void *, U32);

static B32 (__stdcall *PeekMessage)(MSG *, void *, U32, U32, U32);
static S64 (__stdcall *DispatchMessage)(const MSG *);
static void (__stdcall *PostQuitMessage)(S32);
static S64 (__stdcall *DefWindowProc)(void *, U32, U64, S64);
static void *(__stdcall *LoadCursor)(void *, const char *);
static S16 (__stdcall *RegisterClass)(const WNDCLASS *);
static void *(__stdcall *CreateWindowEx)(U32, const char *, const char *, U32, S32, S32, S32, S32, void *, void *, void *, void *);
static B32 (__stdcall *AdjustWindowRect)(RECT *, U32, S32);
static B32 (__cdecl *wsprintf)(char *, const char *, ...);
static B32 (__stdcall *SetWindowText)(void *, const char *);
static B32 (__stdcall *SetProcessDPIAware)(void);
static void *(__stdcall *GetDC)(void *);
static B32 (__stdcall *MessageBox)(void *, const char *, const char *, U32);
static B32 (__stdcall *GetClientRect)(void *, RECT *);
//-------------------------------------------------------------------------------------------------
// DXGI
//-------------------------------------------------------------------------------------------------
typedef enum DXGI_FORMAT { DXGI_FORMAT_UNKNOWN = 0, DXGI_FORMAT_R32G32B32A32_TYPELESS = 1, DXGI_FORMAT_R32G32B32A32_FLOAT = 2, DXGI_FORMAT_R32G32B32A32_UINT = 3, DXGI_FORMAT_R32G32B32A32_SINT = 4, DXGI_FORMAT_R32G32B32_TYPELESS = 5, DXGI_FORMAT_R32G32B32_FLOAT = 6, DXGI_FORMAT_R32G32B32_UINT = 7, DXGI_FORMAT_R32G32B32_SINT = 8, DXGI_FORMAT_R16G16B16A16_TYPELESS = 9, DXGI_FORMAT_R16G16B16A16_FLOAT = 10, DXGI_FORMAT_R16G16B16A16_UNORM = 11, DXGI_FORMAT_R16G16B16A16_UINT = 12, DXGI_FORMAT_R16G16B16A16_SNORM = 13, DXGI_FORMAT_R16G16B16A16_SINT = 14, DXGI_FORMAT_R32G32_TYPELESS = 15, DXGI_FORMAT_R32G32_FLOAT = 16, DXGI_FORMAT_R32G32_UINT = 17, DXGI_FORMAT_R32G32_SINT = 18, DXGI_FORMAT_R32G8X24_TYPELESS = 19, DXGI_FORMAT_D32_FLOAT_S8X24_UINT = 20, DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS = 21, DXGI_FORMAT_X32_TYPELESS_G8X24_UINT = 22, DXGI_FORMAT_R10G10B10A2_TYPELESS = 23, DXGI_FORMAT_R10G10B10A2_UNORM = 24, DXGI_FORMAT_R10G10B10A2_UINT = 25, DXGI_FORMAT_R11G11B10_FLOAT = 26, DXGI_FORMAT_R8G8B8A8_TYPELESS = 27, DXGI_FORMAT_R8G8B8A8_UNORM = 28, DXGI_FORMAT_R8G8B8A8_UNORM_SRGB = 29, DXGI_FORMAT_R8G8B8A8_UINT = 30, DXGI_FORMAT_R8G8B8A8_SNORM = 31, DXGI_FORMAT_R8G8B8A8_SINT = 32, DXGI_FORMAT_R16G16_TYPELESS = 33, DXGI_FORMAT_R16G16_FLOAT = 34, DXGI_FORMAT_R16G16_UNORM = 35, DXGI_FORMAT_R16G16_UINT = 36, DXGI_FORMAT_R16G16_SNORM = 37, DXGI_FORMAT_R16G16_SINT = 38, DXGI_FORMAT_R32_TYPELESS = 39, DXGI_FORMAT_D32_FLOAT = 40, DXGI_FORMAT_R32_FLOAT = 41, DXGI_FORMAT_R32_UINT = 42, DXGI_FORMAT_R32_SINT = 43, DXGI_FORMAT_R24G8_TYPELESS = 44, DXGI_FORMAT_D24_UNORM_S8_UINT = 45, DXGI_FORMAT_R24_UNORM_X8_TYPELESS = 46, DXGI_FORMAT_X24_TYPELESS_G8_UINT = 47, DXGI_FORMAT_R8G8_TYPELESS = 48, DXGI_FORMAT_R8G8_UNORM = 49, DXGI_FORMAT_R8G8_UINT = 50, DXGI_FORMAT_R8G8_SNORM = 51, DXGI_FORMAT_R8G8_SINT = 52, DXGI_FORMAT_R16_TYPELESS = 53, DXGI_FORMAT_R16_FLOAT = 54, DXGI_FORMAT_D16_UNORM = 55, DXGI_FORMAT_R16_UNORM = 56, DXGI_FORMAT_R16_UINT = 57, DXGI_FORMAT_R16_SNORM = 58, DXGI_FORMAT_R16_SINT = 59, DXGI_FORMAT_R8_TYPELESS = 60, DXGI_FORMAT_R8_UNORM = 61, DXGI_FORMAT_R8_UINT = 62, DXGI_FORMAT_R8_SNORM = 63, DXGI_FORMAT_R8_SINT = 64, DXGI_FORMAT_A8_UNORM = 65, DXGI_FORMAT_R1_UNORM = 66, DXGI_FORMAT_R9G9B9E5_SHAREDEXP = 67, DXGI_FORMAT_R8G8_B8G8_UNORM = 68, DXGI_FORMAT_G8R8_G8B8_UNORM = 69, DXGI_FORMAT_BC1_TYPELESS = 70, DXGI_FORMAT_BC1_UNORM = 71, DXGI_FORMAT_BC1_UNORM_SRGB = 72, DXGI_FORMAT_BC2_TYPELESS = 73, DXGI_FORMAT_BC2_UNORM = 74, DXGI_FORMAT_BC2_UNORM_SRGB = 75, DXGI_FORMAT_BC3_TYPELESS = 76, DXGI_FORMAT_BC3_UNORM = 77, DXGI_FORMAT_BC3_UNORM_SRGB = 78, DXGI_FORMAT_BC4_TYPELESS = 79, DXGI_FORMAT_BC4_UNORM = 80, DXGI_FORMAT_BC4_SNORM = 81, DXGI_FORMAT_BC5_TYPELESS = 82, DXGI_FORMAT_BC5_UNORM = 83, DXGI_FORMAT_BC5_SNORM = 84, DXGI_FORMAT_B5G6R5_UNORM = 85, DXGI_FORMAT_B5G5R5A1_UNORM = 86, DXGI_FORMAT_B8G8R8A8_UNORM = 87, DXGI_FORMAT_B8G8R8X8_UNORM = 88, DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM = 89, DXGI_FORMAT_B8G8R8A8_TYPELESS = 90, DXGI_FORMAT_B8G8R8A8_UNORM_SRGB = 91, DXGI_FORMAT_B8G8R8X8_TYPELESS = 92, DXGI_FORMAT_B8G8R8X8_UNORM_SRGB = 93, DXGI_FORMAT_BC6H_TYPELESS = 94, DXGI_FORMAT_BC6H_UF16 = 95, DXGI_FORMAT_BC6H_SF16 = 96, DXGI_FORMAT_BC7_TYPELESS = 97, DXGI_FORMAT_BC7_UNORM = 98, DXGI_FORMAT_BC7_UNORM_SRGB = 99, DXGI_FORMAT_AYUV = 100, DXGI_FORMAT_Y410 = 101, DXGI_FORMAT_Y416 = 102, DXGI_FORMAT_NV12 = 103, DXGI_FORMAT_P010 = 104, DXGI_FORMAT_P016 = 105, DXGI_FORMAT_420_OPAQUE = 106, DXGI_FORMAT_YUY2 = 107, DXGI_FORMAT_Y210 = 108, DXGI_FORMAT_Y216 = 109, DXGI_FORMAT_NV11 = 110, DXGI_FORMAT_AI44 = 111, DXGI_FORMAT_IA44 = 112, DXGI_FORMAT_P8 = 113, DXGI_FORMAT_A8P8 = 114, DXGI_FORMAT_B4G4R4A4_UNORM = 115, DXGI_FORMAT_P208 = 130, DXGI_FORMAT_V208 = 131, DXGI_FORMAT_V408 = 132, DXGI_FORMAT_FORCE_UINT = 0xffffffff } DXGI_FORMAT;

typedef struct DXGI_SAMPLE_DESC { U32 Count; U32 Quality; } DXGI_SAMPLE_DESC;

static S32 (__stdcall *CreateDXGIFactory1)(const GUID *, void **);
//-------------------------------------------------------------------------------------------------
// D3D12
//-------------------------------------------------------------------------------------------------
typedef struct IUnknown IUnknown;
typedef struct IDXGIFactory4 IDXGIFactory4;
typedef struct ID3D12Debug ID3D12Debug;
typedef struct ID3D12Device ID3D12Device;
typedef struct ID3D12CommandQueue ID3D12CommandQueue;
typedef struct ID3D12CommandList ID3D12CommandList;
typedef struct ID3D12Fence ID3D12Fence;
typedef struct ID3D12Resource ID3D12Resource;
typedef struct ID3D12Heap ID3D12Heap;
typedef struct ID3D12RootSignature ID3D12RootSignature;
typedef struct ID3D12CommandAllocator ID3D12CommandAllocator;
typedef struct ID3D12PipelineState ID3D12PipelineState;

typedef enum D3D_FEATURE_LEVEL { D3D_FEATURE_LEVEL_9_1 = 0x9100, D3D_FEATURE_LEVEL_9_2 = 0x9200, D3D_FEATURE_LEVEL_9_3 = 0x9300, D3D_FEATURE_LEVEL_10_0 = 0xa000, D3D_FEATURE_LEVEL_10_1 = 0xa100, D3D_FEATURE_LEVEL_11_0 = 0xb000, D3D_FEATURE_LEVEL_11_1 = 0xb100, D3D_FEATURE_LEVEL_12_0 = 0xc000, D3D_FEATURE_LEVEL_12_1 = 0xc100 } D3D_FEATURE_LEVEL;
typedef enum D3D12_FEATURE { D3D12_FEATURE_D3D12_OPTIONS = 0, D3D12_FEATURE_ARCHITECTURE = 1, D3D12_FEATURE_FEATURE_LEVELS = 2, D3D12_FEATURE_FORMAT_SUPPORT = 3, D3D12_FEATURE_MULTISAMPLE_QUALITY_LEVELS = 4, D3D12_FEATURE_FORMAT_INFO = 5, D3D12_FEATURE_GPU_VIRTUAL_ADDRESS_SUPPORT = 6, D3D12_FEATURE_SHADER_MODEL = 7, D3D12_FEATURE_D3D12_OPTIONS1 = 8, D3D12_FEATURE_ROOT_SIGNATURE = 12 } D3D12_FEATURE;
typedef enum D3D12_COMMAND_QUEUE_FLAGS { D3D12_COMMAND_QUEUE_FLAG_NONE = 0, D3D12_COMMAND_QUEUE_FLAG_DISABLE_GPU_TIMEOUT = 0x1 } D3D12_COMMAND_QUEUE_FLAGS;
typedef enum D3D12_COMMAND_LIST_TYPE { D3D12_COMMAND_LIST_TYPE_DIRECT = 0, D3D12_COMMAND_LIST_TYPE_BUNDLE = 1, D3D12_COMMAND_LIST_TYPE_COMPUTE = 2, D3D12_COMMAND_LIST_TYPE_COPY = 3 } D3D12_COMMAND_LIST_TYPE;
typedef enum D3D12_COMMAND_QUEUE_PRIORITY { D3D12_COMMAND_QUEUE_PRIORITY_NORMAL = 0, D3D12_COMMAND_QUEUE_PRIORITY_HIGH = 100 } D3D12_COMMAND_QUEUE_PRIORITY;
typedef enum D3D12_TILE_RANGE_FLAGS { D3D12_TILE_RANGE_FLAG_NONE = 0, D3D12_TILE_RANGE_FLAG_NULL = 1, D3D12_TILE_RANGE_FLAG_SKIP = 2, D3D12_TILE_RANGE_FLAG_REUSE_SINGLE_TILE = 4 } D3D12_TILE_RANGE_FLAGS;
typedef enum D3D12_TILE_MAPPING_FLAGS { D3D12_TILE_MAPPING_FLAG_NONE = 0, D3D12_TILE_MAPPING_FLAG_NO_HAZARD = 0x1 } D3D12_TILE_MAPPING_FLAGS;
typedef enum D3D12_INDEX_BUFFER_STRIP_CUT_VALUE { D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_DISABLED = 0, D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_0xFFFF = 1, D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_0xFFFFFFFF = 2 } D3D12_INDEX_BUFFER_STRIP_CUT_VALUE;
typedef enum D3D12_PIPELINE_STATE_FLAGS { D3D12_PIPELINE_STATE_FLAG_NONE = 0, D3D12_PIPELINE_STATE_FLAG_TOOL_DEBUG = 0x1 } D3D12_PIPELINE_STATE_FLAGS;
typedef enum D3D12_INPUT_CLASSIFICATION { D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA = 0, D3D12_INPUT_CLASSIFICATION_PER_INSTANCE_DATA = 1 } D3D12_INPUT_CLASSIFICATION;
typedef enum D3D12_BLEND { D3D12_BLEND_ZERO = 1, D3D12_BLEND_ONE = 2, D3D12_BLEND_SRC_COLOR = 3, D3D12_BLEND_INV_SRC_COLOR = 4, D3D12_BLEND_SRC_ALPHA = 5, D3D12_BLEND_INV_SRC_ALPHA = 6, D3D12_BLEND_DEST_ALPHA = 7, D3D12_BLEND_INV_DEST_ALPHA = 8, D3D12_BLEND_DEST_COLOR = 9, D3D12_BLEND_INV_DEST_COLOR = 10, D3D12_BLEND_SRC_ALPHA_SAT = 11, D3D12_BLEND_BLEND_FACTOR = 14, D3D12_BLEND_INV_BLEND_FACTOR = 15, D3D12_BLEND_SRC1_COLOR = 16, D3D12_BLEND_INV_SRC1_COLOR = 17, D3D12_BLEND_SRC1_ALPHA = 18, D3D12_BLEND_INV_SRC1_ALPHA = 19 } D3D12_BLEND;
typedef enum D3D12_BLEND_OP { D3D12_BLEND_OP_ADD = 1, D3D12_BLEND_OP_SUBTRACT = 2, D3D12_BLEND_OP_REV_SUBTRACT = 3, D3D12_BLEND_OP_MIN = 4, D3D12_BLEND_OP_MAX = 5 } D3D12_BLEND_OP;
typedef enum D3D12_COLOR_WRITE_ENABLE { D3D12_COLOR_WRITE_ENABLE_RED = 1, D3D12_COLOR_WRITE_ENABLE_GREEN = 2, D3D12_COLOR_WRITE_ENABLE_BLUE = 4, D3D12_COLOR_WRITE_ENABLE_ALPHA = 8, D3D12_COLOR_WRITE_ENABLE_ALL = D3D12_COLOR_WRITE_ENABLE_RED | D3D12_COLOR_WRITE_ENABLE_GREEN | D3D12_COLOR_WRITE_ENABLE_BLUE | D3D12_COLOR_WRITE_ENABLE_ALPHA } D3D12_COLOR_WRITE_ENABLE;
typedef enum D3D12_LOGIC_OP { D3D12_LOGIC_OP_CLEAR = 0, D3D12_LOGIC_OP_SET = (D3D12_LOGIC_OP_CLEAR + 1), D3D12_LOGIC_OP_COPY = (D3D12_LOGIC_OP_SET + 1), D3D12_LOGIC_OP_COPY_INVERTED = (D3D12_LOGIC_OP_COPY + 1), D3D12_LOGIC_OP_NOOP = (D3D12_LOGIC_OP_COPY_INVERTED + 1), D3D12_LOGIC_OP_INVERT = (D3D12_LOGIC_OP_NOOP + 1), D3D12_LOGIC_OP_AND = (D3D12_LOGIC_OP_INVERT + 1), D3D12_LOGIC_OP_NAND = (D3D12_LOGIC_OP_AND + 1), D3D12_LOGIC_OP_OR = (D3D12_LOGIC_OP_NAND + 1), D3D12_LOGIC_OP_NOR = (D3D12_LOGIC_OP_OR + 1), D3D12_LOGIC_OP_XOR = (D3D12_LOGIC_OP_NOR + 1), D3D12_LOGIC_OP_EQUIV = (D3D12_LOGIC_OP_XOR + 1), D3D12_LOGIC_OP_AND_REVERSE = (D3D12_LOGIC_OP_EQUIV + 1), D3D12_LOGIC_OP_AND_INVERTED = (D3D12_LOGIC_OP_AND_REVERSE + 1), D3D12_LOGIC_OP_OR_REVERSE = (D3D12_LOGIC_OP_AND_INVERTED + 1), D3D12_LOGIC_OP_OR_INVERTED = (D3D12_LOGIC_OP_OR_REVERSE + 1) } D3D12_LOGIC_OP;
typedef enum D3D12_CULL_MODE { D3D12_CULL_MODE_NONE = 1, D3D12_CULL_MODE_FRONT = 2, D3D12_CULL_MODE_BACK = 3 } D3D12_CULL_MODE;
typedef enum D3D12_COMPARISON_FUNC { D3D12_COMPARISON_FUNC_NEVER = 1, D3D12_COMPARISON_FUNC_LESS = 2, D3D12_COMPARISON_FUNC_EQUAL = 3, D3D12_COMPARISON_FUNC_LESS_EQUAL = 4, D3D12_COMPARISON_FUNC_GREATER = 5, D3D12_COMPARISON_FUNC_NOT_EQUAL = 6, D3D12_COMPARISON_FUNC_GREATER_EQUAL = 7, D3D12_COMPARISON_FUNC_ALWAYS = 8 } D3D12_COMPARISON_FUNC;
typedef enum D3D12_DEPTH_WRITE_MASK { D3D12_DEPTH_WRITE_MASK_ZERO = 0, D3D12_DEPTH_WRITE_MASK_ALL = 1 } D3D12_DEPTH_WRITE_MASK;
typedef enum D3D12_STENCIL_OP { D3D12_STENCIL_OP_KEEP = 1, D3D12_STENCIL_OP_ZERO = 2, D3D12_STENCIL_OP_REPLACE = 3, D3D12_STENCIL_OP_INCR_SAT = 4, D3D12_STENCIL_OP_DECR_SAT = 5, D3D12_STENCIL_OP_INVERT = 6, D3D12_STENCIL_OP_INCR = 7, D3D12_STENCIL_OP_DECR = 8 } D3D12_STENCIL_OP;
typedef enum D3D12_CONSERVATIVE_RASTERIZATION_MODE { D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF = 0, D3D12_CONSERVATIVE_RASTERIZATION_MODE_ON = 1 } D3D12_CONSERVATIVE_RASTERIZATION_MODE;
typedef enum D3D12_FILL_MODE { D3D12_FILL_MODE_WIREFRAME = 2, D3D12_FILL_MODE_SOLID = 3 } D3D12_FILL_MODE;
typedef enum D3D12_PRIMITIVE_TOPOLOGY { D3D_PRIMITIVE_TOPOLOGY_UNDEFINED = 0, D3D_PRIMITIVE_TOPOLOGY_POINTLIST = 1, D3D_PRIMITIVE_TOPOLOGY_LINELIST = 2, D3D_PRIMITIVE_TOPOLOGY_LINESTRIP = 3, D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST = 4, D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP = 5, D3D_PRIMITIVE_TOPOLOGY_LINELIST_ADJ = 10, D3D_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ = 11, D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ = 12, D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ = 13, D3D_PRIMITIVE_TOPOLOGY_1_CONTROL_POINT_PATCHLIST = 33, D3D_PRIMITIVE_TOPOLOGY_2_CONTROL_POINT_PATCHLIST = 34, D3D_PRIMITIVE_TOPOLOGY_3_CONTROL_POINT_PATCHLIST = 35, D3D_PRIMITIVE_TOPOLOGY_4_CONTROL_POINT_PATCHLIST = 36, D3D_PRIMITIVE_TOPOLOGY_5_CONTROL_POINT_PATCHLIST = 37, D3D_PRIMITIVE_TOPOLOGY_6_CONTROL_POINT_PATCHLIST = 38, D3D_PRIMITIVE_TOPOLOGY_7_CONTROL_POINT_PATCHLIST = 39, D3D_PRIMITIVE_TOPOLOGY_8_CONTROL_POINT_PATCHLIST = 40, D3D_PRIMITIVE_TOPOLOGY_9_CONTROL_POINT_PATCHLIST = 41, D3D_PRIMITIVE_TOPOLOGY_10_CONTROL_POINT_PATCHLIST = 42, D3D_PRIMITIVE_TOPOLOGY_11_CONTROL_POINT_PATCHLIST = 43, D3D_PRIMITIVE_TOPOLOGY_12_CONTROL_POINT_PATCHLIST = 44, D3D_PRIMITIVE_TOPOLOGY_13_CONTROL_POINT_PATCHLIST = 45, D3D_PRIMITIVE_TOPOLOGY_14_CONTROL_POINT_PATCHLIST = 46, D3D_PRIMITIVE_TOPOLOGY_15_CONTROL_POINT_PATCHLIST = 47, D3D_PRIMITIVE_TOPOLOGY_16_CONTROL_POINT_PATCHLIST = 48, D3D_PRIMITIVE_TOPOLOGY_17_CONTROL_POINT_PATCHLIST = 49, D3D_PRIMITIVE_TOPOLOGY_18_CONTROL_POINT_PATCHLIST = 50, D3D_PRIMITIVE_TOPOLOGY_19_CONTROL_POINT_PATCHLIST = 51, D3D_PRIMITIVE_TOPOLOGY_20_CONTROL_POINT_PATCHLIST = 52, D3D_PRIMITIVE_TOPOLOGY_21_CONTROL_POINT_PATCHLIST = 53, D3D_PRIMITIVE_TOPOLOGY_22_CONTROL_POINT_PATCHLIST = 54, D3D_PRIMITIVE_TOPOLOGY_23_CONTROL_POINT_PATCHLIST = 55, D3D_PRIMITIVE_TOPOLOGY_24_CONTROL_POINT_PATCHLIST = 56, D3D_PRIMITIVE_TOPOLOGY_25_CONTROL_POINT_PATCHLIST = 57, D3D_PRIMITIVE_TOPOLOGY_26_CONTROL_POINT_PATCHLIST = 58, D3D_PRIMITIVE_TOPOLOGY_27_CONTROL_POINT_PATCHLIST = 59, D3D_PRIMITIVE_TOPOLOGY_28_CONTROL_POINT_PATCHLIST = 60, D3D_PRIMITIVE_TOPOLOGY_29_CONTROL_POINT_PATCHLIST = 61, D3D_PRIMITIVE_TOPOLOGY_30_CONTROL_POINT_PATCHLIST = 62, D3D_PRIMITIVE_TOPOLOGY_31_CONTROL_POINT_PATCHLIST = 63, D3D_PRIMITIVE_TOPOLOGY_32_CONTROL_POINT_PATCHLIST = 64 } D3D12_PRIMITIVE_TOPOLOGY;
typedef enum D3D12_PRIMITIVE_TOPOLOGY_TYPE { D3D12_PRIMITIVE_TOPOLOGY_TYPE_UNDEFINED = 0, D3D12_PRIMITIVE_TOPOLOGY_TYPE_POINT = 1, D3D12_PRIMITIVE_TOPOLOGY_TYPE_LINE = 2, D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE = 3, D3D12_PRIMITIVE_TOPOLOGY_TYPE_PATCH = 4 } D3D12_PRIMITIVE_TOPOLOGY_TYPE;
typedef enum D3D12_DESCRIPTOR_HEAP_TYPE { D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV = 0, D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER = (D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV + 1), D3D12_DESCRIPTOR_HEAP_TYPE_RTV = (D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER + 1), D3D12_DESCRIPTOR_HEAP_TYPE_DSV = (D3D12_DESCRIPTOR_HEAP_TYPE_RTV + 1), D3D12_DESCRIPTOR_HEAP_TYPE_NUM_TYPES = (D3D12_DESCRIPTOR_HEAP_TYPE_DSV + 1) } D3D12_DESCRIPTOR_HEAP_TYPE;
typedef enum D3D12_DESCRIPTOR_HEAP_FLAGS { D3D12_DESCRIPTOR_HEAP_FLAG_NONE = 0, D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE = 0x1 } D3D12_DESCRIPTOR_HEAP_FLAGS;
typedef enum D3D12_BUFFER_SRV_FLAGS { D3D12_BUFFER_SRV_FLAG_NONE = 0, D3D12_BUFFER_SRV_FLAG_RAW = 0x1 } D3D12_BUFFER_SRV_FLAGS;
typedef enum D3D12_SRV_DIMENSION { D3D12_SRV_DIMENSION_UNKNOWN = 0, D3D12_SRV_DIMENSION_BUFFER = 1, D3D12_SRV_DIMENSION_TEXTURE1D = 2, D3D12_SRV_DIMENSION_TEXTURE1DARRAY = 3, D3D12_SRV_DIMENSION_TEXTURE2D = 4, D3D12_SRV_DIMENSION_TEXTURE2DARRAY = 5, D3D12_SRV_DIMENSION_TEXTURE2DMS = 6, D3D12_SRV_DIMENSION_TEXTURE2DMSARRAY = 7, D3D12_SRV_DIMENSION_TEXTURE3D = 8, D3D12_SRV_DIMENSION_TEXTURECUBE = 9, D3D12_SRV_DIMENSION_TEXTURECUBEARRAY = 10 } D3D12_SRV_DIMENSION;

typedef U64 D3D12_GPU_VIRTUAL_ADDRESS;
typedef struct D3D12_CPU_DESCRIPTOR_HANDLE { U64 ptr; } D3D12_CPU_DESCRIPTOR_HANDLE;
typedef struct D3D12_GPU_DESCRIPTOR_HANDLE { U64 ptr; } D3D12_GPU_DESCRIPTOR_HANDLE;
typedef struct D3D12_CONSTANT_BUFFER_VIEW_DESC { D3D12_GPU_VIRTUAL_ADDRESS BufferLocation; U32 SizeInBytes; } D3D12_CONSTANT_BUFFER_VIEW_DESC;
typedef struct D3D12_DESCRIPTOR_HEAP_DESC { D3D12_DESCRIPTOR_HEAP_TYPE Type; U32 NumDescriptors; D3D12_DESCRIPTOR_HEAP_FLAGS Flags; U32 NodeMask; } D3D12_DESCRIPTOR_HEAP_DESC;
typedef struct D3D12_SO_DECLARATION_ENTRY { U32 Stream; const char *SemanticName; U32 SemanticIndex; U8 StartComponent; U8 ComponentCount; U8 OutputSlot; } D3D12_SO_DECLARATION_ENTRY;
typedef struct D3D12_STREAM_OUTPUT_DESC { const D3D12_SO_DECLARATION_ENTRY *pSODeclaration; U32 NumEntries; const U32 *pBufferStrides; U32 NumStrides; U32 RasterizedStream; } D3D12_STREAM_OUTPUT_DESC;
typedef struct D3D12_COMMAND_QUEUE_DESC { D3D12_COMMAND_LIST_TYPE Type; S32 Priority; D3D12_COMMAND_QUEUE_FLAGS Flags; U32 NodeMask; } D3D12_COMMAND_QUEUE_DESC;
typedef struct D3D12_TILED_RESOURCE_COORDINATE { U32 X; U32 Y; U32 Z; U32 Subresource; } D3D12_TILED_RESOURCE_COORDINATE;
typedef struct D3D12_TILE_REGION_SIZE { U32 NumTiles; S32 UseBox; U32 Width; U16 Height; U16 Depth; } D3D12_TILE_REGION_SIZE;
typedef struct D3D12_SHADER_BYTECODE { const void *pShaderBytecode; U64 BytecodeLength; } D3D12_SHADER_BYTECODE;
typedef struct D3D12_INPUT_ELEMENT_DESC { const char *SemanticName; U32 SemanticIndex; DXGI_FORMAT Format; U32 InputSlot; U32 AlignedByteOffset; D3D12_INPUT_CLASSIFICATION InputSlotClass; U32 InstanceDataStepRate; } D3D12_INPUT_ELEMENT_DESC;
typedef struct D3D12_INPUT_LAYOUT_DESC { const D3D12_INPUT_ELEMENT_DESC *pInputElementDescs; U32 NumElements; } D3D12_INPUT_LAYOUT_DESC;
typedef struct D3D12_CACHED_PIPELINE_STATE { const void *pCachedBlob; U64 CachedBlobSizeInBytes; } D3D12_CACHED_PIPELINE_STATE;
typedef struct D3D12_VIEWPORT { F32 TopLeftX; F32 TopLeftY; F32 Width; F32 Height; F32 MinDepth; F32 MaxDepth; } D3D12_VIEWPORT;
typedef struct D3D12_DEPTH_STENCILOP_DESC { D3D12_STENCIL_OP StencilFailOp; D3D12_STENCIL_OP StencilDepthFailOp; D3D12_STENCIL_OP StencilPassOp; D3D12_COMPARISON_FUNC StencilFunc; } D3D12_DEPTH_STENCILOP_DESC;
typedef struct D3D12_DEPTH_STENCIL_DESC { S32 DepthEnable; D3D12_DEPTH_WRITE_MASK DepthWriteMask; D3D12_COMPARISON_FUNC DepthFunc; S32 StencilEnable; U8 StencilReadMask; U8 StencilWriteMask; D3D12_DEPTH_STENCILOP_DESC FrontFace; D3D12_DEPTH_STENCILOP_DESC BackFace; } D3D12_DEPTH_STENCIL_DESC;
typedef struct D3D12_RENDER_TARGET_BLEND_DESC { S32 BlendEnable; S32 LogicOpEnable; D3D12_BLEND SrcBlend; D3D12_BLEND DestBlend; D3D12_BLEND_OP BlendOp; D3D12_BLEND SrcBlendAlpha; D3D12_BLEND DestBlendAlpha; D3D12_BLEND_OP BlendOpAlpha; D3D12_LOGIC_OP LogicOp; U8 RenderTargetWriteMask; } D3D12_RENDER_TARGET_BLEND_DESC;
typedef struct D3D12_BLEND_DESC { S32 AlphaToCoverageEnable; S32 IndependentBlendEnable; D3D12_RENDER_TARGET_BLEND_DESC RenderTarget[8]; } D3D12_BLEND_DESC;
typedef struct D3D12_RASTERIZER_DESC { D3D12_FILL_MODE FillMode; D3D12_CULL_MODE CullMode; S32 FrontCounterClockwise; S32 DepthBias; F32 DepthBiasClamp; F32 SlopeScaledDepthBias; S32 DepthClipEnable; S32 MultisampleEnable; S32 AntialiasedLineEnable; U32 ForcedSampleCount; D3D12_CONSERVATIVE_RASTERIZATION_MODE ConservativeRaster; } D3D12_RASTERIZER_DESC;
typedef struct D3D12_GRAPHICS_PIPELINE_STATE_DESC { ID3D12RootSignature *pRootSignature; D3D12_SHADER_BYTECODE VS; D3D12_SHADER_BYTECODE PS; D3D12_SHADER_BYTECODE DS; D3D12_SHADER_BYTECODE HS; D3D12_SHADER_BYTECODE GS; D3D12_STREAM_OUTPUT_DESC StreamOutput; D3D12_BLEND_DESC BlendState; U32 SampleMask; D3D12_RASTERIZER_DESC RasterizerState; D3D12_DEPTH_STENCIL_DESC DepthStencilState; D3D12_INPUT_LAYOUT_DESC InputLayout; D3D12_INDEX_BUFFER_STRIP_CUT_VALUE IBStripCutValue; D3D12_PRIMITIVE_TOPOLOGY_TYPE PrimitiveTopologyType; U32 NumRenderTargets; DXGI_FORMAT RTVFormats[8]; DXGI_FORMAT DSVFormat; DXGI_SAMPLE_DESC SampleDesc; U32 NodeMask; D3D12_CACHED_PIPELINE_STATE CachedPSO; D3D12_PIPELINE_STATE_FLAGS Flags; } D3D12_GRAPHICS_PIPELINE_STATE_DESC;
typedef struct D3D12_COMPUTE_PIPELINE_STATE_DESC { ID3D12RootSignature *pRootSignature; D3D12_SHADER_BYTECODE CS; U32 NodeMask; D3D12_CACHED_PIPELINE_STATE CachedPSO; D3D12_PIPELINE_STATE_FLAGS Flags; } D3D12_COMPUTE_PIPELINE_STATE_DESC;
typedef struct D3D12_BUFFER_SRV { U64 FirstElement; U32 NumElements; U32 StructureByteStride; D3D12_BUFFER_SRV_FLAGS Flags; } D3D12_BUFFER_SRV;
typedef struct D3D12_TEX1D_SRV { U32 MostDetailedMip; U32 MipLevels; F32 ResourceMinLODClamp; } D3D12_TEX1D_SRV;
typedef struct D3D12_TEX1D_ARRAY_SRV { U32 MostDetailedMip; U32 MipLevels; U32 FirstArraySlice; U32 ArraySize; F32 ResourceMinLODClamp; } D3D12_TEX1D_ARRAY_SRV;
typedef struct D3D12_TEX2D_SRV { U32 MostDetailedMip; U32 MipLevels; U32 PlaneSlice; F32 ResourceMinLODClamp; } D3D12_TEX2D_SRV;
typedef struct D3D12_TEX2D_ARRAY_SRV { U32 MostDetailedMip; U32 MipLevels; U32 FirstArraySlice; U32 ArraySize; U32 PlaneSlice; F32 ResourceMinLODClamp; } D3D12_TEX2D_ARRAY_SRV;
typedef struct D3D12_TEX3D_SRV { U32 MostDetailedMip; U32 MipLevels; F32 ResourceMinLODClamp; } D3D12_TEX3D_SRV;
typedef struct D3D12_TEXCUBE_SRV { U32 MostDetailedMip; U32 MipLevels; F32 ResourceMinLODClamp; } D3D12_TEXCUBE_SRV;
typedef struct D3D12_TEXCUBE_ARRAY_SRV { U32 MostDetailedMip; U32 MipLevels; U32 First2DArrayFace; U32 NumCubes; F32 ResourceMinLODClamp; } D3D12_TEXCUBE_ARRAY_SRV;
typedef struct D3D12_TEX2DMS_SRV { U32 UnusedField_NothingToDefine; } D3D12_TEX2DMS_SRV;
typedef struct D3D12_TEX2DMS_ARRAY_SRV { U32 FirstArraySlice; U32 ArraySize; } D3D12_TEX2DMS_ARRAY_SRV;
typedef struct D3D12_SHADER_RESOURCE_VIEW_DESC { DXGI_FORMAT Format; D3D12_SRV_DIMENSION ViewDimension; U32 Shader4ComponentMapping; union { D3D12_BUFFER_SRV Buffer; D3D12_TEX1D_SRV Texture1D; D3D12_TEX1D_ARRAY_SRV Texture1DArray; D3D12_TEX2D_SRV Texture2D; D3D12_TEX2D_ARRAY_SRV Texture2DArray; D3D12_TEX2DMS_SRV Texture2DMS; D3D12_TEX2DMS_ARRAY_SRV Texture2DMSArray; D3D12_TEX3D_SRV Texture3D; D3D12_TEXCUBE_SRV TextureCube; D3D12_TEXCUBE_ARRAY_SRV TextureCubeArray; }; } D3D12_SHADER_RESOURCE_VIEW_DESC;

typedef struct ID3D12DebugVt {
    S32 (__stdcall *QueryInterface)(ID3D12Debug *, const GUID *, void **);
    U32 (__stdcall *AddRef)(ID3D12Debug *);
    U32 (__stdcall *Release)(ID3D12Debug *);
    void (__stdcall *EnableDebugLayer)(ID3D12Debug *);
} ID3D12DebugVt; struct ID3D12Debug { const ID3D12DebugVt *vt; };

typedef struct ID3D12CommandQueueVt {
    S32 (__stdcall *QueryInterface)(ID3D12CommandQueue *, const GUID *, void **);
    U32 (__stdcall *AddRef)(ID3D12CommandQueue *);
    U32 (__stdcall *Release)(ID3D12CommandQueue *);
    S32 (__stdcall *GetPrivateData)(ID3D12CommandQueue *, const GUID *, U32 *, void *);
    S32 (__stdcall *SetPrivateData)(ID3D12CommandQueue *, const GUID *, U32, const void *);
    S32 (__stdcall *SetPrivateDataInterface)(ID3D12CommandQueue *, const GUID *, const IUnknown *);
    S32 (__stdcall *SetName)(ID3D12CommandQueue *, const U16 *);
    S32 (__stdcall *GetDevice)(ID3D12CommandQueue *, const GUID *, void **);
    void (__stdcall *UpdateTileMappings)(ID3D12CommandQueue *, ID3D12Resource *, U32, const D3D12_TILED_RESOURCE_COORDINATE *, const D3D12_TILE_REGION_SIZE *, ID3D12Heap *, U32, const D3D12_TILE_RANGE_FLAGS *, const U32 *, const U32 *, D3D12_TILE_MAPPING_FLAGS);
    void (__stdcall *CopyTileMappings)(ID3D12CommandQueue *, ID3D12Resource *, const D3D12_TILED_RESOURCE_COORDINATE *, ID3D12Resource *, const D3D12_TILED_RESOURCE_COORDINATE *, const D3D12_TILE_REGION_SIZE *, D3D12_TILE_MAPPING_FLAGS);
    void (__stdcall *ExecuteCommandLists)(ID3D12CommandQueue *, U32, ID3D12CommandList *const *);
    void (__stdcall *SetMarker)(ID3D12CommandQueue *, U32, const void *, U32);
    void (__stdcall *BeginEvent)(ID3D12CommandQueue *, U32, const void *, U32);
    void (__stdcall *EndEvent)(ID3D12CommandQueue *);
    S32 (__stdcall *Signal)(ID3D12CommandQueue *, ID3D12Fence *, U64);
    S32 (__stdcall *Wait)(ID3D12CommandQueue *, ID3D12Fence *, U64);
    S32 (__stdcall *GetTimestampFrequency)(ID3D12CommandQueue *, U64 *);
    S32 (__stdcall *GetClockCalibration)(ID3D12CommandQueue *, U64 *, U64 *);
    D3D12_COMMAND_QUEUE_DESC *(__stdcall *GetDesc)(ID3D12CommandQueue *, D3D12_COMMAND_QUEUE_DESC *);
} ID3D12CommandQueueVt; struct ID3D12CommandQueue { const ID3D12CommandQueueVt *vt; };

typedef struct ID3D12DeviceVt {
    S32 (__stdcall *QueryInterface)(ID3D12Device *, const GUID *, void **);
    U32 (__stdcall *AddRef)(ID3D12Device *);
    U32 (__stdcall *Release)(ID3D12Device *);
    S32 (__stdcall *GetPrivateData)(ID3D12Device *, const GUID *, U32 *, void *);
    S32 (__stdcall *SetPrivateData)(ID3D12Device *, const GUID *, U32, const void *);
    S32 (__stdcall *SetPrivateDataInterface)(ID3D12Device *, const GUID *, const IUnknown *);
    S32 (__stdcall *SetName)(ID3D12Device *, const U16 *);
    U32 (__stdcall *GetNodeCount)(ID3D12Device *);
    S32 (__stdcall *CreateCommandQueue)(ID3D12Device *, const D3D12_COMMAND_QUEUE_DESC *, const GUID *, void **);
    S32 (__stdcall *CreateCommandAllocator)(ID3D12Device *, D3D12_COMMAND_LIST_TYPE, const GUID *, void **);
    S32 (__stdcall *CreateGraphicsPipelineState)(ID3D12Device *, const D3D12_GRAPHICS_PIPELINE_STATE_DESC *, const GUID *, void **);
    S32 (__stdcall *CreateComputePipelineState)(ID3D12Device *, const D3D12_COMPUTE_PIPELINE_STATE_DESC *, const GUID *, void **);
    S32 (__stdcall *CreateCommandList)(ID3D12Device *, U32, D3D12_COMMAND_LIST_TYPE, ID3D12CommandAllocator *, ID3D12PipelineState *, const GUID *, void **);
    S32 (__stdcall *CheckFeatureSupport)(ID3D12Device *, D3D12_FEATURE, void *, U32);
    S32 (__stdcall *CreateDescriptorHeap)(ID3D12Device *, const D3D12_DESCRIPTOR_HEAP_DESC *, const GUID *, void **);
    U32 (__stdcall *GetDescriptorHandleIncrementSize)(ID3D12Device *, D3D12_DESCRIPTOR_HEAP_TYPE);
    S32 (__stdcall *CreateRootSignature)(ID3D12Device *, U32, const void *, U64, const GUID *, void **);
    void (__stdcall *CreateConstantBufferView)(ID3D12Device *, const D3D12_CONSTANT_BUFFER_VIEW_DESC *, D3D12_CPU_DESCRIPTOR_HANDLE);
    void (__stdcall *CreateShaderResourceView)(ID3D12Device *, ID3D12Resource *, const D3D12_SHADER_RESOURCE_VIEW_DESC *, D3D12_CPU_DESCRIPTOR_HANDLE);
    void (__stdcall *CreateUnorderedAccessView)(ID3D12Device *, ID3D12Resource *, ID3D12Resource *, const D3D12_UNORDERED_ACCESS_VIEW_DESC *, D3D12_CPU_DESCRIPTOR_HANDLE);
    void (__stdcall *CreateRenderTargetView)(ID3D12Device *, ID3D12Resource *, const D3D12_RENDER_TARGET_VIEW_DESC *, D3D12_CPU_DESCRIPTOR_HANDLE);
    void (__stdcall *CreateDepthStencilView)(ID3D12Device *, ID3D12Resource *, const D3D12_DEPTH_STENCIL_VIEW_DESC *, D3D12_CPU_DESCRIPTOR_HANDLE);
    void (__stdcall *CreateSampler)(ID3D12Device *, const D3D12_SAMPLER_DESC *, D3D12_CPU_DESCRIPTOR_HANDLE);
    void (__stdcall *CopyDescriptors)(ID3D12Device *, U32, const D3D12_CPU_DESCRIPTOR_HANDLE *, const U32 *, U32, const D3D12_CPU_DESCRIPTOR_HANDLE *, const U32 *, D3D12_DESCRIPTOR_HEAP_TYPE);
    void (__stdcall *CopyDescriptorsSimple)(ID3D12Device *, U32, D3D12_CPU_DESCRIPTOR_HANDLE, D3D12_CPU_DESCRIPTOR_HANDLE, D3D12_DESCRIPTOR_HEAP_TYPE);
    D3D12_RESOURCE_ALLOCATION_INFO *(__stdcall *GetResourceAllocationInfo)(ID3D12Device *, U32, U32, const D3D12_RESOURCE_DESC *, D3D12_RESOURCE_ALLOCATION_INFO *);
    D3D12_HEAP_PROPERTIES *(__stdcall *GetCustomHeapProperties)(ID3D12Device *, U32, D3D12_HEAP_TYPE, D3D12_HEAP_PROPERTIES *);
    S32 (__stdcall *CreateCommittedResource)(ID3D12Device *, const D3D12_HEAP_PROPERTIES *, D3D12_HEAP_FLAGS, const D3D12_RESOURCE_DESC *, D3D12_RESOURCE_STATES, const D3D12_CLEAR_VALUE *, const GUID *, void **);
    S32 (__stdcall *CreateHeap)(ID3D12Device *, const D3D12_HEAP_DESC *, const GUID *, void **);
    S32 (__stdcall *CreatePlacedResource)(ID3D12Device *, ID3D12Heap *, U64, const D3D12_RESOURCE_DESC *, D3D12_RESOURCE_STATES, const D3D12_CLEAR_VALUE *, const GUID *, void **);
    S32 (__stdcall *CreateReservedResource)(ID3D12Device *, const D3D12_RESOURCE_DESC *, D3D12_RESOURCE_STATES, const D3D12_CLEAR_VALUE *, const GUID *, void **);
    S32 (__stdcall *CreateSharedHandle)(ID3D12Device *, ID3D12DeviceChild *, const SECURITY_ATTRIBUTES *, U32, U16 *, void **);
    S32 (__stdcall *OpenSharedHandle)(ID3D12Device *, void *, const GUID *, void **);
    S32 (__stdcall *OpenSharedHandleByName)(ID3D12Device *self, U16 *name, U32 access, void **);
    S32 (__stdcall *MakeResident)(ID3D12Device *, U32, ID3D12Pageable *const *);
    S32 (__stdcall *Evict)(ID3D12Device *, U32, ID3D12Pageable *const *);
    S32 (__stdcall *CreateFence)(ID3D12Device *, U64, D3D12_FENCE_FLAGS, const GUID *, void **);
    S32 (__stdcall *GetDeviceRemovedReason)(ID3D12Device *);
    void (__stdcall *GetCopyableFootprints)(ID3D12Device *, const D3D12_RESOURCE_DESC *, U32, U32, U64, D3D12_PLACED_SUBRESOURCE_FOOTPRINT *, U32 *, U64 *, U64 *);
    S32 (__stdcall *CreateQueryHeap)(ID3D12Device *, const D3D12_QUERY_HEAP_DESC *, const GUID *, void **);
    S32 (__stdcall *SetStablePowerState)(ID3D12Device *, B32);
    S32 (__stdcall *CreateCommandSignature)(ID3D12Device *, const D3D12_COMMAND_SIGNATURE_DESC *, ID3D12RootSignature *, const GUID *, void **);
    void (__stdcall *GetResourceTiling)(ID3D12Device *, ID3D12Resource *, U32 *, D3D12_PACKED_MIP_INFO *, D3D12_TILE_SHAPE *, U32 *, U32, D3D12_SUBRESOURCE_TILING *);
    S64 (__stdcall *GetAdapterLuid)(ID3D12Device *);
} ID3D12DeviceVt; struct ID3D12Device { const ID3D12DeviceVt *vt; };

static S32 (__stdcall *D3D12CreateDevice)(IUnknown *, D3D_FEATURE_LEVEL, const GUID *, void **);
static S32 (__stdcall *D3D12GetDebugInterface)(const GUID *, void **);

static const GUID IID_ID3D12Debug = { 0x344488b7,0x6846,0x474b,0xb9,0x89,0xf0,0x27,0x44,0x82,0x45,0xe0 };
static const GUID IID_IDXGISwapChain = { 0x310d36a0,0xd2e7,0x4c0a,0xaa,0x04,0x6a,0x9d,0x23,0xb8,0x88,0x6a };
static const GUID IID_IDXGISwapChain3 = { 0x94d99bdb,0xf1f8,0x4ab0,0xb2,0x36,0x7d,0xa0,0x17,0x0e,0xda,0xb1 };
static const GUID IID_IDXGIFactory4 = { 0x1bc6ea02,0xef36,0x464f,0xbf,0x0c,0x21,0xca,0x39,0xe5,0x16,0x8a };
static const GUID IID_ID3D12GraphicsCommandList = { 0x5b160d0f,0xac1b,0x4185,0x8b,0xa8,0xb3,0xae,0x42,0xa5,0xa4,0x55 };
static const GUID IID_ID3D12CommandQueue = { 0x0ec870a6,0x5d7e,0x4c22,0x8c,0xfc,0x5b,0xaa,0xe0,0x76,0x16,0xed };
static const GUID IID_ID3D12Device = { 0x189819f1,0x1db6,0x4b57,0xbe,0x54,0x18,0x21,0x33,0x9b,0x85,0xf7 };
static const GUID IID_ID3D12DescriptorHeap = { 0x8efb471d,0x616c,0x4f49,0x90,0xf7,0x12,0x7b,0xb7,0x63,0xfa,0x51 };
static const GUID IID_ID3D12Resource = { 0x696442be,0xa72e,0x4059,0xbc,0x79,0x5b,0x5c,0x98,0x04,0x0f,0xad };
static const GUID IID_ID3D12RootSignature = { 0xc54a6b66,0x72df,0x4ee8,0x8b,0xe5,0xa9,0x46,0xa1,0x42,0x92,0x14 };
static const GUID IID_ID3D12CommandAllocator = { 0x6102dee4,0xaf59,0x4b09,0xb9,0x99,0xb4,0x4d,0x73,0xf0,0x9b,0x24 };
static const GUID IID_ID3D12Fence = { 0x0a753dcf,0xc4d8,0x4b91,0xad,0xf6,0xbe,0x5a,0x60,0xd9,0x5a,0x76 };
static const GUID IID_ID3D12PipelineState = { 0x765a30f3,0xf624,0x4c6f,0xa8,0x28,0xac,0xe9,0x48,0x62,0x24,0x45 };
//-------------------------------------------------------------------------------------------------
// Global data
//-------------------------------------------------------------------------------------------------
struct {
    U32 viewportWidth, viewportHeight;
    const char* demoName;
} G;
//-------------------------------------------------------------------------------------------------
// DirectX12 Subsystem
//-------------------------------------------------------------------------------------------------
struct {
    ID3D12Device *device;
} Dx;

struct {
    IDXGIFactory4 *dxgiFactory;
} _Dx;

static void DxInit(void *window)
{
    VHR(CreateDXGIFactory1(&IID_IDXGIFactory4, &_DX.dxgiFactory));
#ifdef _DEBUG
    ID3D12Debug *dbg = NULL;
    D3D12GetDebugInterface(&IID_ID3D12Debug, &dbg);
    if (dbg) {
        dbg->vt->EnableDebugLayer(dbg);
        dbg->vt->Release(dbg);
    }
#endif
    if (D3D12CreateDevice(NULL, D3D_FEATURE_LEVEL_11_1, &IID_ID3D12Device, &Dx.device) != 0) {
        MessageBox(window, "Program requires Windows 10 machine with DirectX 12 support (D3D_FEATURE_LEVEL_11_1 or better).", "Error", 0);
        ExitProcess(1);
    }
    D3D12_COMMAND_QUEUE_DESC cmdQueueDesc = {
        .Flags = D3D12_COMMAND_QUEUE_FLAG_NONE,
        .Priority = D3D12_COMMAND_QUEUE_PRIORITY_NORMAL,
        .Type = D3D12_COMMAND_LIST_TYPE_DIRECT
    };
    VHR(Dx.device->vt->CreateCommandQueue(Dx.device, &cmdQueueDesc, &IID_ID3D12CommandQueue, &Dx.cmdQueue));
}

static F64 GetTime(void)
{
    static S64 frequency, startCounter;
    if (frequency == 0) {
        QueryPerformanceCounter(&startCounter);
        QueryPerformanceFrequency(&frequency);
    }
    S64 counter;
    QueryPerformanceCounter(&counter);
    return (counter - startCounter) / (F64)frequency;
}

static void UpdateFrameTime(void *window, const char *name, F64 *timeOut, F32 *deltaTimeOut)
{
    static F64 prevTime;
    static F64 prevHeaderUpdateTime;
    static U32 frameCount;

    if (prevTime == 0.0) {
        prevTime = GetTime();
        prevHeaderUpdateTime = prevTime;
    }

    *timeOut = GetTime();
    *deltaTimeOut = (F32)(*timeOut - prevTime);
    prevTime = *timeOut;

    if ((*timeOut - prevHeaderUpdateTime) >= 1.0) {
        F64 fps = frameCount / (*timeOut - prevHeaderUpdateTime);
        F64 us = (1.0 / fps) * 1000000.0;
        char text[256];
        wsprintf(text, "[%d fps  %d us] %s", (S32)fps, (S32)us, name);
        SetWindowText(window, text);
        prevHeaderUpdateTime = *timeOut;
        frameCount = 0;
    }
    frameCount++;
}

static S64 __stdcall ProcessWindowMessage(void *window, U32 message, U64 wparam, S64 lparam)
{
    switch (message) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_KEYDOWN:
            if (wparam == VK_ESCAPE) {
                PostQuitMessage(0);
                return 0;
            }
            break;
    }
    return DefWindowProc(window, message, wparam, lparam);
}

static void *CreateWindow(const char *name, U32 width, U32 height)
{
    WNDCLASS winclass = {
        .lpfnWndProc = ProcessWindowMessage,
        .hInstance = GetModuleHandle(NULL),
        .hCursor = LoadCursor(NULL, IDC_ARROW),
        .lpszClassName = name,
    };
    if (!RegisterClass(&winclass))
        assert(0);

    RECT rect = { 0, 0, (S32)width, (S32)height };
    if (!AdjustWindowRect(&rect, WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX, 0))
        assert(0);

    void *window = CreateWindowEx(
        0, name, name, WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX | WS_VISIBLE,
        CW_USEDEFAULT, CW_USEDEFAULT,
        rect.right - rect.left, rect.bottom - rect.top,
        NULL, NULL, NULL, 0);
    assert(window);
    return window;
}

void Start(void)
{
    G.viewportWidth = 1920;
    G.viewportHeight = 1080;
    G.demoName = "demo01";

    void *kernel32 = LoadLibraryA("kernel32.dll");
    OutputDebugString = GetProcAddress(kernel32, "OutputDebugStringA");
    GetModuleHandle = GetProcAddress(kernel32, "GetModuleHandleA");
    QueryPerformanceCounter = GetProcAddress(kernel32, "QueryPerformanceCounter");
    QueryPerformanceFrequency = GetProcAddress(kernel32, "QueryPerformanceFrequency");
    VirtualAlloc = GetProcAddress(kernel32, "VirtualAlloc");
    VirtualFree = GetProcAddress(kernel32, "VirtualFree");
    ExitProcess = GetProcAddress(kernel32, "ExitProcess");
    CreateFile = GetProcAddress(kernel32, "CreateFileA");
    ReadFile = GetProcAddress(kernel32, "ReadFile");
    GetFileSize = GetProcAddress(kernel32, "GetFileSize");
    CloseHandle = GetProcAddress(kernel32, "CloseHandle");
    Sleep = GetProcAddress(kernel32, "Sleep");
    HeapAlloc = GetProcAddress(kernel32, "HeapAlloc");
    HeapFree = GetProcAddress(kernel32, "HeapFree");
    HeapReAlloc = GetProcAddress(kernel32, "HeapReAlloc");
    GetProcessHeap = GetProcAddress(kernel32, "GetProcessHeap");
    CreateEventEx = GetProcAddress(kernel32, "CreateEventExA");
    WaitForSingleObject = GetProcAddress(kernel32, "WaitForSingleObject");

    void *user32 = LoadLibraryA("user32.dll");
    PeekMessage = GetProcAddress(user32, "PeekMessageA");
    DispatchMessage = GetProcAddress(user32, "DispatchMessageA");
    PostQuitMessage = GetProcAddress(user32, "PostQuitMessage");
    DefWindowProc = GetProcAddress(user32, "DefWindowProcA");
    LoadCursor = GetProcAddress(user32, "LoadCursorA");
    RegisterClass = GetProcAddress(user32, "RegisterClassA");
    CreateWindowEx = GetProcAddress(user32, "CreateWindowExA");
    AdjustWindowRect = GetProcAddress(user32, "AdjustWindowRect");
    wsprintf = GetProcAddress(user32, "wsprintfA");
    SetWindowText = GetProcAddress(user32, "SetWindowTextA");
    SetProcessDPIAware = GetProcAddress(user32, "SetProcessDPIAware");
    GetDC = GetProcAddress(user32, "GetDC");
    MessageBox = GetProcAddress(user32, "MessageBoxA");
    GetClientRect = GetProcAddress(user32, "GetClientRect");

    void *d3d12 = LoadLibraryA("d3d12.dll");
    if (!d3d12) {
        MessageBox(NULL, "Program requires Windows 10 machine with DirectX 12 support (D3D_FEATURE_LEVEL_11_1 or better).", "Error", 0);
        ExitProcess(1);
    }
    D3D12CreateDevice = GetProcAddress(d3d12, "D3D12CreateDevice");
    D3D12GetDebugInterface = GetProcAddress(d3d12, "D3D12GetDebugInterface");

    void *dxgi = LoadLibraryA("dxgi.dll");
    CreateDXGIFactory1 = GetProcAddress(dxgi, "CreateDXGIFactory1");

    SetProcessDPIAware();

    // init window
    void *window = CreateWindow(G.demoName, G.viewportWidth, G.viewportHeight);

    DxInit(window);

    for (;;) {
        MSG message = { 0 };
        if (PeekMessage(&message, 0, 0, 0, PM_REMOVE)) {
            DispatchMessage(&message);
            if (message.message == WM_QUIT)
                break;
        } else {
            F64 frameTime;
            F32 frameDeltaTime;
            UpdateFrameTime(window, G.demoName, &frameTime, &frameDeltaTime);
        }
    }

    ExitProcess(0);
}
