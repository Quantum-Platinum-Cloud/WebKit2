/*
 * Copyright (C) 2020 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)

#include "GraphicsContextGLIdentifier.h"
#include "MessageReceiver.h"
#include "MessageSender.h"
#include "RemoteGraphicsContextGLMessages.h"
#include "RemoteResourceCacheProxy.h"
#include "WebCoreArgumentCoders.h"

#include <WebCore/NotImplemented.h>
#include <WebCore/RemoteGraphicsContextGLProxyBase.h>
#include <wtf/HashMap.h>
#include <wtf/WeakPtr.h>


namespace WebKit {

// Web process side implementation of GraphicsContextGL interface. The implementation
// converts the interface to a sequence of IPC messages and sends the messages to
// RemoteGraphicsContextGL in GPU process.
// The implementation is largely generated by running Tools/Scripts/generate-gpup-webgl.
class RemoteGraphicsContextGLProxy final
    : public IPC::MessageSender
    , private IPC::MessageReceiver
    , public CanMakeWeakPtr<RemoteGraphicsContextGLProxy>
    , public WebCore::RemoteGraphicsContextGLProxyBase {
public:
    static RefPtr<RemoteGraphicsContextGLProxy> create(const WebCore::GraphicsContextGLAttributes&);
    ~RemoteGraphicsContextGLProxy() final;

    // IPC::MessageSender overrides.
    IPC::Connection* messageSenderConnection() const final;
    uint64_t messageSenderDestinationID() const final;

    // IPC::MessageReceiver overrides.
    void didReceiveMessage(IPC::Connection&, IPC::Decoder&) final;

    // RemoteGraphicsContextGLProxyBase overrides.
    void reshape(int width, int height) final;
    void prepareForDisplay() final;
    using WebCore::RemoteGraphicsContextGLProxyBase::isEnabled;
    void ensureExtensionEnabled(const String& extension) final;
    void notifyMarkContextChanged() final;
    void simulateContextChanged() final;
    void paintRenderingResultsToCanvas(WebCore::ImageBuffer*) final;
    RefPtr<WebCore::ImageData> paintRenderingResultsToImageData() final;
    void paintCompositedResultsToCanvas(WebCore::ImageBuffer*) final;

    // Functions with a generated implementation. This list is used by generate-gpup-webgl script.
    void setFailNextGPUStatusCheck() final;
    void synthesizeGLError(GCGLenum error) final;
    bool moveErrorsToSyntheticErrorList() final;
    void activeTexture(GCGLenum texture) final;
    void attachShader(PlatformGLObject program, PlatformGLObject shader) final;
    void bindAttribLocation(PlatformGLObject arg0, GCGLuint index, const String& name) final;
    void bindBuffer(GCGLenum target, PlatformGLObject arg1) final;
    void bindFramebuffer(GCGLenum target, PlatformGLObject arg1) final;
    void bindRenderbuffer(GCGLenum target, PlatformGLObject arg1) final;
    void bindTexture(GCGLenum target, PlatformGLObject arg1) final;
    void blendColor(GCGLclampf red, GCGLclampf green, GCGLclampf blue, GCGLclampf alpha) final;
    void blendEquation(GCGLenum mode) final;
    void blendEquationSeparate(GCGLenum modeRGB, GCGLenum modeAlpha) final;
    void blendFunc(GCGLenum sfactor, GCGLenum dfactor) final;
    void blendFuncSeparate(GCGLenum srcRGB, GCGLenum dstRGB, GCGLenum srcAlpha, GCGLenum dstAlpha) final;
    GCGLenum checkFramebufferStatus(GCGLenum target) final;
    void clear(GCGLbitfield mask) final;
    void clearColor(GCGLclampf red, GCGLclampf green, GCGLclampf blue, GCGLclampf alpha) final;
    void clearDepth(GCGLclampf depth) final;
    void clearStencil(GCGLint s) final;
    void colorMask(GCGLboolean red, GCGLboolean green, GCGLboolean blue, GCGLboolean alpha) final;
    void compileShader(PlatformGLObject arg0) final;
    void copyTexImage2D(GCGLenum target, GCGLint level, GCGLenum internalformat, GCGLint x, GCGLint y, GCGLsizei width, GCGLsizei height, GCGLint border) final;
    void copyTexSubImage2D(GCGLenum target, GCGLint level, GCGLint xoffset, GCGLint yoffset, GCGLint x, GCGLint y, GCGLsizei width, GCGLsizei height) final;
    PlatformGLObject createBuffer() final;
    PlatformGLObject createFramebuffer() final;
    PlatformGLObject createProgram() final;
    PlatformGLObject createRenderbuffer() final;
    PlatformGLObject createShader(GCGLenum arg0) final;
    PlatformGLObject createTexture() final;
    void cullFace(GCGLenum mode) final;
    void deleteBuffer(PlatformGLObject arg0) final;
    void deleteFramebuffer(PlatformGLObject arg0) final;
    void deleteProgram(PlatformGLObject arg0) final;
    void deleteRenderbuffer(PlatformGLObject arg0) final;
    void deleteShader(PlatformGLObject arg0) final;
    void deleteTexture(PlatformGLObject arg0) final;
    void depthFunc(GCGLenum func) final;
    void depthMask(GCGLboolean flag) final;
    void depthRange(GCGLclampf zNear, GCGLclampf zFar) final;
    void detachShader(PlatformGLObject arg0, PlatformGLObject arg1) final;
    void disable(GCGLenum cap) final;
    void disableVertexAttribArray(GCGLuint index) final;
    void drawArrays(GCGLenum mode, GCGLint first, GCGLsizei count) final;
    void drawElements(GCGLenum mode, GCGLsizei count, GCGLenum type, GCGLintptr offset) final;
    void enable(GCGLenum cap) final;
    void enableVertexAttribArray(GCGLuint index) final;
    void finish() final;
    void flush() final;
    void framebufferRenderbuffer(GCGLenum target, GCGLenum attachment, GCGLenum renderbuffertarget, PlatformGLObject arg3) final;
    void framebufferTexture2D(GCGLenum target, GCGLenum attachment, GCGLenum textarget, PlatformGLObject arg3, GCGLint level) final;
    void frontFace(GCGLenum mode) final;
    void generateMipmap(GCGLenum target) final;
    bool getActiveAttrib(PlatformGLObject program, GCGLuint index, ActiveInfo& arg2) final;
    bool getActiveUniform(PlatformGLObject program, GCGLuint index, ActiveInfo& arg2) final;
    GCGLint getAttribLocation(PlatformGLObject arg0, const String& name) final;
    GCGLint getBufferParameteri(GCGLenum target, GCGLenum pname) final;
    String getString(GCGLenum name) final;
    void getFloatv(GCGLenum pname, GCGLSpan<GCGLfloat> value) final;
    void getIntegerv(GCGLenum pname, GCGLSpan<GCGLint> value) final;
    GCGLint64 getInteger64(GCGLenum pname) final;
    GCGLint64 getInteger64i(GCGLenum pname, GCGLuint index) final;
    GCGLint getProgrami(PlatformGLObject program, GCGLenum pname) final;
    void getBooleanv(GCGLenum pname, GCGLSpan<GCGLboolean> value) final;
    GCGLenum getError() final;
    GCGLint getFramebufferAttachmentParameteri(GCGLenum target, GCGLenum attachment, GCGLenum pname) final;
    String getProgramInfoLog(PlatformGLObject arg0) final;
    GCGLint getRenderbufferParameteri(GCGLenum target, GCGLenum pname) final;
    GCGLint getShaderi(PlatformGLObject arg0, GCGLenum pname) final;
    String getShaderInfoLog(PlatformGLObject arg0) final;
    void getShaderPrecisionFormat(GCGLenum shaderType, GCGLenum precisionType, GCGLSpan<GCGLint, 2> range, GCGLint* precision) final;
    String getShaderSource(PlatformGLObject arg0) final;
    GCGLfloat getTexParameterf(GCGLenum target, GCGLenum pname) final;
    GCGLint getTexParameteri(GCGLenum target, GCGLenum pname) final;
    void getUniformfv(PlatformGLObject program, GCGLint location, GCGLSpan<GCGLfloat> value) final;
    void getUniformiv(PlatformGLObject program, GCGLint location, GCGLSpan<GCGLint> value) final;
    void getUniformuiv(PlatformGLObject program, GCGLint location, GCGLSpan<GCGLuint> value) final;
    GCGLint getUniformLocation(PlatformGLObject arg0, const String& name) final;
    GCGLsizeiptr getVertexAttribOffset(GCGLuint index, GCGLenum pname) final;
    void hint(GCGLenum target, GCGLenum mode) final;
    GCGLboolean isBuffer(PlatformGLObject arg0) final;
    GCGLboolean isEnabled(GCGLenum cap) final;
    GCGLboolean isFramebuffer(PlatformGLObject arg0) final;
    GCGLboolean isProgram(PlatformGLObject arg0) final;
    GCGLboolean isRenderbuffer(PlatformGLObject arg0) final;
    GCGLboolean isShader(PlatformGLObject arg0) final;
    GCGLboolean isTexture(PlatformGLObject arg0) final;
    void lineWidth(GCGLfloat arg0) final;
    void linkProgram(PlatformGLObject arg0) final;
    void pixelStorei(GCGLenum pname, GCGLint param) final;
    void polygonOffset(GCGLfloat factor, GCGLfloat units) final;
    void renderbufferStorage(GCGLenum target, GCGLenum internalformat, GCGLsizei width, GCGLsizei height) final;
    void sampleCoverage(GCGLclampf value, GCGLboolean invert) final;
    void scissor(GCGLint x, GCGLint y, GCGLsizei width, GCGLsizei height) final;
    void shaderSource(PlatformGLObject arg0, const String&) final;
    void stencilFunc(GCGLenum func, GCGLint ref, GCGLuint mask) final;
    void stencilFuncSeparate(GCGLenum face, GCGLenum func, GCGLint ref, GCGLuint mask) final;
    void stencilMask(GCGLuint mask) final;
    void stencilMaskSeparate(GCGLenum face, GCGLuint mask) final;
    void stencilOp(GCGLenum fail, GCGLenum zfail, GCGLenum zpass) final;
    void stencilOpSeparate(GCGLenum face, GCGLenum fail, GCGLenum zfail, GCGLenum zpass) final;
    void texParameterf(GCGLenum target, GCGLenum pname, GCGLfloat param) final;
    void texParameteri(GCGLenum target, GCGLenum pname, GCGLint param) final;
    void uniform1f(GCGLint location, GCGLfloat x) final;
    void uniform1fv(GCGLint location, GCGLSpan<const GCGLfloat> v) final;
    void uniform1i(GCGLint location, GCGLint x) final;
    void uniform1iv(GCGLint location, GCGLSpan<const GCGLint> v) final;
    void uniform2f(GCGLint location, GCGLfloat x, GCGLfloat y) final;
    void uniform2fv(GCGLint location, GCGLSpan<const GCGLfloat> v) final;
    void uniform2i(GCGLint location, GCGLint x, GCGLint y) final;
    void uniform2iv(GCGLint location, GCGLSpan<const GCGLint> v) final;
    void uniform3f(GCGLint location, GCGLfloat x, GCGLfloat y, GCGLfloat z) final;
    void uniform3fv(GCGLint location, GCGLSpan<const GCGLfloat> v) final;
    void uniform3i(GCGLint location, GCGLint x, GCGLint y, GCGLint z) final;
    void uniform3iv(GCGLint location, GCGLSpan<const GCGLint> v) final;
    void uniform4f(GCGLint location, GCGLfloat x, GCGLfloat y, GCGLfloat z, GCGLfloat w) final;
    void uniform4fv(GCGLint location, GCGLSpan<const GCGLfloat> v) final;
    void uniform4i(GCGLint location, GCGLint x, GCGLint y, GCGLint z, GCGLint w) final;
    void uniform4iv(GCGLint location, GCGLSpan<const GCGLint> v) final;
    void uniformMatrix2fv(GCGLint location, GCGLboolean transpose, GCGLSpan<const GCGLfloat> value) final;
    void uniformMatrix3fv(GCGLint location, GCGLboolean transpose, GCGLSpan<const GCGLfloat> value) final;
    void uniformMatrix4fv(GCGLint location, GCGLboolean transpose, GCGLSpan<const GCGLfloat> value) final;
    void useProgram(PlatformGLObject arg0) final;
    void validateProgram(PlatformGLObject arg0) final;
    void vertexAttrib1f(GCGLuint index, GCGLfloat x) final;
    void vertexAttrib1fv(GCGLuint index, GCGLSpan<const GCGLfloat, 1> values) final;
    void vertexAttrib2f(GCGLuint index, GCGLfloat x, GCGLfloat y) final;
    void vertexAttrib2fv(GCGLuint index, GCGLSpan<const GCGLfloat, 2> values) final;
    void vertexAttrib3f(GCGLuint index, GCGLfloat x, GCGLfloat y, GCGLfloat z) final;
    void vertexAttrib3fv(GCGLuint index, GCGLSpan<const GCGLfloat, 3> values) final;
    void vertexAttrib4f(GCGLuint index, GCGLfloat x, GCGLfloat y, GCGLfloat z, GCGLfloat w) final;
    void vertexAttrib4fv(GCGLuint index, GCGLSpan<const GCGLfloat, 4> values) final;
    void vertexAttribPointer(GCGLuint index, GCGLint size, GCGLenum type, GCGLboolean normalized, GCGLsizei stride, GCGLintptr offset) final;
    void viewport(GCGLint x, GCGLint y, GCGLsizei width, GCGLsizei height) final;
    void bufferData(GCGLenum target, GCGLsizeiptr arg1, GCGLenum usage) final;
    void bufferData(GCGLenum target, GCGLSpan<const GCGLvoid> data, GCGLenum usage) final;
    void bufferSubData(GCGLenum target, GCGLintptr offset, GCGLSpan<const GCGLvoid> data) final;
    void readnPixels(GCGLint x, GCGLint y, GCGLsizei width, GCGLsizei height, GCGLenum format, GCGLenum type, GCGLSpan<GCGLvoid> data) final;
    void readnPixels(GCGLint x, GCGLint y, GCGLsizei width, GCGLsizei height, GCGLenum format, GCGLenum type, GCGLintptr offset) final;
    void texImage2D(GCGLenum target, GCGLint level, GCGLenum internalformat, GCGLsizei width, GCGLsizei height, GCGLint border, GCGLenum format, GCGLenum type, GCGLSpan<const GCGLvoid> pixels) final;
    void texImage2D(GCGLenum target, GCGLint level, GCGLenum internalformat, GCGLsizei width, GCGLsizei height, GCGLint border, GCGLenum format, GCGLenum type, GCGLintptr offset) final;
    void texSubImage2D(GCGLenum target, GCGLint level, GCGLint xoffset, GCGLint yoffset, GCGLsizei width, GCGLsizei height, GCGLenum format, GCGLenum type, GCGLSpan<const GCGLvoid> pixels) final;
    void texSubImage2D(GCGLenum target, GCGLint level, GCGLint xoffset, GCGLint yoffset, GCGLsizei width, GCGLsizei height, GCGLenum format, GCGLenum type, GCGLintptr offset) final;
    void compressedTexImage2D(GCGLenum target, GCGLint level, GCGLenum internalformat, GCGLsizei width, GCGLsizei height, GCGLint border, GCGLsizei imageSize, GCGLSpan<const GCGLvoid> data) final;
    void compressedTexImage2D(GCGLenum target, GCGLint level, GCGLenum internalformat, GCGLsizei width, GCGLsizei height, GCGLint border, GCGLsizei imageSize, GCGLintptr offset) final;
    void compressedTexSubImage2D(GCGLenum target, GCGLint level, GCGLint xoffset, GCGLint yoffset, GCGLsizei width, GCGLsizei height, GCGLenum format, GCGLsizei imageSize, GCGLSpan<const GCGLvoid> data) final;
    void compressedTexSubImage2D(GCGLenum target, GCGLint level, GCGLint xoffset, GCGLint yoffset, GCGLsizei width, GCGLsizei height, GCGLenum format, GCGLsizei imageSize, GCGLintptr offset) final;
    void drawArraysInstanced(GCGLenum mode, GCGLint first, GCGLsizei count, GCGLsizei primcount) final;
    void drawElementsInstanced(GCGLenum mode, GCGLsizei count, GCGLenum type, GCGLintptr offset, GCGLsizei primcount) final;
    void vertexAttribDivisor(GCGLuint index, GCGLuint divisor) final;
    PlatformGLObject createVertexArray() final;
    void deleteVertexArray(PlatformGLObject arg0) final;
    GCGLboolean isVertexArray(PlatformGLObject arg0) final;
    void bindVertexArray(PlatformGLObject arg0) final;
    void copyBufferSubData(GCGLenum readTarget, GCGLenum writeTarget, GCGLintptr readOffset, GCGLintptr writeOffset, GCGLsizeiptr) final;
    void getBufferSubData(GCGLenum target, GCGLintptr offset, GCGLSpan<GCGLvoid> data) final;
    void blitFramebuffer(GCGLint srcX0, GCGLint srcY0, GCGLint srcX1, GCGLint srcY1, GCGLint dstX0, GCGLint dstY0, GCGLint dstX1, GCGLint dstY1, GCGLbitfield mask, GCGLenum filter) final;
    void framebufferTextureLayer(GCGLenum target, GCGLenum attachment, PlatformGLObject texture, GCGLint level, GCGLint layer) final;
    void invalidateFramebuffer(GCGLenum target, GCGLSpan<const GCGLenum> attachments) final;
    void invalidateSubFramebuffer(GCGLenum target, GCGLSpan<const GCGLenum> attachments, GCGLint x, GCGLint y, GCGLsizei width, GCGLsizei height) final;
    void readBuffer(GCGLenum src) final;
    void renderbufferStorageMultisample(GCGLenum target, GCGLsizei samples, GCGLenum internalformat, GCGLsizei width, GCGLsizei height) final;
    void texStorage2D(GCGLenum target, GCGLsizei levels, GCGLenum internalformat, GCGLsizei width, GCGLsizei height) final;
    void texStorage3D(GCGLenum target, GCGLsizei levels, GCGLenum internalformat, GCGLsizei width, GCGLsizei height, GCGLsizei depth) final;
    void texImage3D(GCGLenum target, GCGLint level, GCGLint internalformat, GCGLsizei width, GCGLsizei height, GCGLsizei depth, GCGLint border, GCGLenum format, GCGLenum type, GCGLSpan<const GCGLvoid> pixels) final;
    void texImage3D(GCGLenum target, GCGLint level, GCGLint internalformat, GCGLsizei width, GCGLsizei height, GCGLsizei depth, GCGLint border, GCGLenum format, GCGLenum type, GCGLintptr offset) final;
    void texSubImage3D(GCGLenum target, GCGLint level, GCGLint xoffset, GCGLint yoffset, GCGLint zoffset, GCGLsizei width, GCGLsizei height, GCGLsizei depth, GCGLenum format, GCGLenum type, GCGLSpan<const GCGLvoid> pixels) final;
    void texSubImage3D(GCGLenum target, GCGLint level, GCGLint xoffset, GCGLint yoffset, GCGLint zoffset, GCGLsizei width, GCGLsizei height, GCGLsizei depth, GCGLenum format, GCGLenum type, GCGLintptr offset) final;
    void copyTexSubImage3D(GCGLenum target, GCGLint level, GCGLint xoffset, GCGLint yoffset, GCGLint zoffset, GCGLint x, GCGLint y, GCGLsizei width, GCGLsizei height) final;
    void compressedTexImage3D(GCGLenum target, GCGLint level, GCGLenum internalformat, GCGLsizei width, GCGLsizei height, GCGLsizei depth, GCGLint border, GCGLsizei imageSize, GCGLSpan<const GCGLvoid> data) final;
    void compressedTexImage3D(GCGLenum target, GCGLint level, GCGLenum internalformat, GCGLsizei width, GCGLsizei height, GCGLsizei depth, GCGLint border, GCGLsizei imageSize, GCGLintptr offset) final;
    void compressedTexSubImage3D(GCGLenum target, GCGLint level, GCGLint xoffset, GCGLint yoffset, GCGLint zoffset, GCGLsizei width, GCGLsizei height, GCGLsizei depth, GCGLenum format, GCGLsizei imageSize, GCGLSpan<const GCGLvoid> data) final;
    void compressedTexSubImage3D(GCGLenum target, GCGLint level, GCGLint xoffset, GCGLint yoffset, GCGLint zoffset, GCGLsizei width, GCGLsizei height, GCGLsizei depth, GCGLenum format, GCGLsizei imageSize, GCGLintptr offset) final;
    GCGLint getFragDataLocation(PlatformGLObject program, const String& name) final;
    void uniform1ui(GCGLint location, GCGLuint v0) final;
    void uniform2ui(GCGLint location, GCGLuint v0, GCGLuint v1) final;
    void uniform3ui(GCGLint location, GCGLuint v0, GCGLuint v1, GCGLuint v2) final;
    void uniform4ui(GCGLint location, GCGLuint v0, GCGLuint v1, GCGLuint v2, GCGLuint v3) final;
    void uniform1uiv(GCGLint location, GCGLSpan<const GCGLuint> data) final;
    void uniform2uiv(GCGLint location, GCGLSpan<const GCGLuint> data) final;
    void uniform3uiv(GCGLint location, GCGLSpan<const GCGLuint> data) final;
    void uniform4uiv(GCGLint location, GCGLSpan<const GCGLuint> data) final;
    void uniformMatrix2x3fv(GCGLint location, GCGLboolean transpose, GCGLSpan<const GCGLfloat> data) final;
    void uniformMatrix3x2fv(GCGLint location, GCGLboolean transpose, GCGLSpan<const GCGLfloat> data) final;
    void uniformMatrix2x4fv(GCGLint location, GCGLboolean transpose, GCGLSpan<const GCGLfloat> data) final;
    void uniformMatrix4x2fv(GCGLint location, GCGLboolean transpose, GCGLSpan<const GCGLfloat> data) final;
    void uniformMatrix3x4fv(GCGLint location, GCGLboolean transpose, GCGLSpan<const GCGLfloat> data) final;
    void uniformMatrix4x3fv(GCGLint location, GCGLboolean transpose, GCGLSpan<const GCGLfloat> data) final;
    void vertexAttribI4i(GCGLuint index, GCGLint x, GCGLint y, GCGLint z, GCGLint w) final;
    void vertexAttribI4iv(GCGLuint index, GCGLSpan<const GCGLint, 4> values) final;
    void vertexAttribI4ui(GCGLuint index, GCGLuint x, GCGLuint y, GCGLuint z, GCGLuint w) final;
    void vertexAttribI4uiv(GCGLuint index, GCGLSpan<const GCGLuint, 4> values) final;
    void vertexAttribIPointer(GCGLuint index, GCGLint size, GCGLenum type, GCGLsizei stride, GCGLintptr offset) final;
    void drawRangeElements(GCGLenum mode, GCGLuint start, GCGLuint end, GCGLsizei count, GCGLenum type, GCGLintptr offset) final;
    void drawBuffers(GCGLSpan<const GCGLenum> bufs) final;
    void clearBufferiv(GCGLenum buffer, GCGLint drawbuffer, GCGLSpan<const GCGLint> values) final;
    void clearBufferuiv(GCGLenum buffer, GCGLint drawbuffer, GCGLSpan<const GCGLuint> values) final;
    void clearBufferfv(GCGLenum buffer, GCGLint drawbuffer, GCGLSpan<const GCGLfloat> values) final;
    void clearBufferfi(GCGLenum buffer, GCGLint drawbuffer, GCGLfloat depth, GCGLint stencil) final;
    PlatformGLObject createQuery() final;
    void deleteQuery(PlatformGLObject query) final;
    GCGLboolean isQuery(PlatformGLObject query) final;
    void beginQuery(GCGLenum target, PlatformGLObject query) final;
    void endQuery(GCGLenum target) final;
    PlatformGLObject getQuery(GCGLenum target, GCGLenum pname) final;
    GCGLuint getQueryObjectui(PlatformGLObject query, GCGLenum pname) final;
    PlatformGLObject createSampler() final;
    void deleteSampler(PlatformGLObject sampler) final;
    GCGLboolean isSampler(PlatformGLObject sampler) final;
    void bindSampler(GCGLuint unit, PlatformGLObject sampler) final;
    void samplerParameteri(PlatformGLObject sampler, GCGLenum pname, GCGLint param) final;
    void samplerParameterf(PlatformGLObject sampler, GCGLenum pname, GCGLfloat param) final;
    GCGLfloat getSamplerParameterf(PlatformGLObject sampler, GCGLenum pname) final;
    GCGLint getSamplerParameteri(PlatformGLObject sampler, GCGLenum pname) final;
    GCGLsync fenceSync(GCGLenum condition, GCGLbitfield flags) final;
    GCGLboolean isSync(GCGLsync arg0) final;
    void deleteSync(GCGLsync arg0) final;
    GCGLenum clientWaitSync(GCGLsync arg0, GCGLbitfield flags, GCGLuint64 timeout) final;
    void waitSync(GCGLsync arg0, GCGLbitfield flags, GCGLint64 timeout) final;
    GCGLint getSynci(GCGLsync arg0, GCGLenum pname) final;
    PlatformGLObject createTransformFeedback() final;
    void deleteTransformFeedback(PlatformGLObject id) final;
    GCGLboolean isTransformFeedback(PlatformGLObject id) final;
    void bindTransformFeedback(GCGLenum target, PlatformGLObject id) final;
    void beginTransformFeedback(GCGLenum primitiveMode) final;
    void endTransformFeedback() final;
    void transformFeedbackVaryings(PlatformGLObject program, const Vector<String>& varyings, GCGLenum bufferMode) final;
    void getTransformFeedbackVarying(PlatformGLObject program, GCGLuint index, ActiveInfo& arg2) final;
    void pauseTransformFeedback() final;
    void resumeTransformFeedback() final;
    void bindBufferBase(GCGLenum target, GCGLuint index, PlatformGLObject buffer) final;
    void bindBufferRange(GCGLenum target, GCGLuint index, PlatformGLObject buffer, GCGLintptr offset, GCGLsizeiptr) final;
    Vector<GCGLuint> getUniformIndices(PlatformGLObject program, const Vector<String>& uniformNames) final;
    Vector<GCGLint> getActiveUniforms(PlatformGLObject program, const Vector<GCGLuint>& uniformIndices, GCGLenum pname) final;
    GCGLuint getUniformBlockIndex(PlatformGLObject program, const String& uniformBlockName) final;
    String getActiveUniformBlockName(PlatformGLObject program, GCGLuint uniformBlockIndex) final;
    void uniformBlockBinding(PlatformGLObject program, GCGLuint uniformBlockIndex, GCGLuint uniformBlockBinding) final;
    void getActiveUniformBlockiv(GCGLuint program, GCGLuint uniformBlockIndex, GCGLenum pname, GCGLSpan<GCGLint> params) final;
    GCGLint getGraphicsResetStatusARB() final;
    void blitFramebufferANGLE(GCGLint srcX0, GCGLint srcY0, GCGLint srcX1, GCGLint srcY1, GCGLint dstX0, GCGLint dstY0, GCGLint dstX1, GCGLint dstY1, GCGLbitfield mask, GCGLenum filter) final;
    void renderbufferStorageMultisampleANGLE(GCGLenum target, GCGLsizei samples, GCGLenum internalformat, GCGLsizei width, GCGLsizei height) final;
    PlatformGLObject createVertexArrayOES() final;
    void deleteVertexArrayOES(PlatformGLObject arg0) final;
    GCGLboolean isVertexArrayOES(PlatformGLObject arg0) final;
    void bindVertexArrayOES(PlatformGLObject arg0) final;
    String getTranslatedShaderSourceANGLE(PlatformGLObject arg0) final;
    void insertEventMarkerEXT(const String& arg0) final;
    void pushGroupMarkerEXT(const String& arg0) final;
    void popGroupMarkerEXT() final;
    void drawBuffersEXT(GCGLSpan<const GCGLenum> bufs) final;
    void drawArraysInstancedANGLE(GCGLenum mode, GCGLint first, GCGLsizei count, GCGLsizei primcount) final;
    void drawElementsInstancedANGLE(GCGLenum mode, GCGLsizei count, GCGLenum type, GCGLvoidptr offset, GCGLsizei primcount) final;
    void vertexAttribDivisorANGLE(GCGLuint index, GCGLuint divisor) final;
    void getInternalformativ(GCGLenum target, GCGLenum internalformat, GCGLenum pname, GCGLSpan<GCGLint> params) final;
    void readPixelsRobustANGLE(GCGLint x, GCGLint y, GCGLsizei width, GCGLsizei height, GCGLenum format, GCGLenum type, GCGLsizei bufSize, GCGLsizei* length, GCGLsizei* columns, GCGLsizei* rows, GCGLvoid* pixels) final;
    void texParameterfvRobustANGLE(GCGLenum target, GCGLenum pname, GCGLsizei bufSize, const GCGLfloat* params) final;
    void texParameterivRobustANGLE(GCGLenum target, GCGLenum pname, GCGLsizei bufSize, const GCGLint* params) final;
    void getQueryivRobustANGLE(GCGLenum target, GCGLenum pname, GCGLsizei bufSize, GCGLsizei* length, GCGLint* params) final;
    void getQueryObjectuivRobustANGLE(GCGLuint id, GCGLenum pname, GCGLsizei bufSize, GCGLsizei* length, GCGLuint* params) final;
    void getBufferPointervRobustANGLE(GCGLenum target, GCGLenum pname, GCGLsizei bufSize, GCGLsizei* length, GCGLvoid** params) final;
    void getVertexAttribIivRobustANGLE(GCGLuint index, GCGLenum pname, GCGLsizei bufSize, GCGLsizei* length, GCGLint* params) final;
    void getVertexAttribIuivRobustANGLE(GCGLuint index, GCGLenum pname, GCGLsizei bufSize, GCGLsizei* length, GCGLuint* params) final;
    void getUniformuivRobustANGLE(GCGLuint program, GCGLint location, GCGLsizei bufSize, GCGLsizei* length, GCGLuint* params) final;
    void getBufferParameteri64vRobustANGLE(GCGLenum target, GCGLenum pname, GCGLsizei bufSize, GCGLsizei* length, GCGLint64* params) final;
    void samplerParameterivRobustANGLE(GCGLuint sampler, GCGLenum pname, GCGLsizei bufSize, const GCGLint* param) final;
    void samplerParameterfvRobustANGLE(GCGLuint sampler, GCGLenum pname, GCGLsizei bufSize, const GCGLfloat* param) final;
    void getSamplerParameterivRobustANGLE(GCGLuint sampler, GCGLenum pname, GCGLsizei bufSize, GCGLsizei* length, GCGLint* params) final;
    void getSamplerParameterfvRobustANGLE(GCGLuint sampler, GCGLenum pname, GCGLsizei bufSize, GCGLsizei* length, GCGLfloat* params) final;
    void getFramebufferParameterivRobustANGLE(GCGLenum target, GCGLenum pname, GCGLsizei bufSize, GCGLsizei* length, GCGLint* params) final;
    void getProgramInterfaceivRobustANGLE(GCGLuint program, GCGLenum programInterface, GCGLenum pname, GCGLsizei bufSize, GCGLsizei* length, GCGLint* params) final;
    void getBooleani_vRobustANGLE(GCGLenum target, GCGLuint index, GCGLsizei bufSize, GCGLsizei* length, GCGLboolean* data) final; // NOLINT
    void getMultisamplefvRobustANGLE(GCGLenum pname, GCGLuint index, GCGLsizei bufSize, GCGLsizei* length, GCGLfloat* val) final;
    void getTexLevelParameterivRobustANGLE(GCGLenum target, GCGLint level, GCGLenum pname, GCGLsizei bufSize, GCGLsizei* length, GCGLint* params) final;
    void getTexLevelParameterfvRobustANGLE(GCGLenum target, GCGLint level, GCGLenum pname, GCGLsizei bufSize, GCGLsizei* length, GCGLfloat* params) final;
    void getPointervRobustANGLERobustANGLE(GCGLenum pname, GCGLsizei bufSize, GCGLsizei* length, GCGLvoid** params) final;
    void getnUniformfvRobustANGLE(GCGLuint program, GCGLint location, GCGLsizei bufSize, GCGLsizei* length, GCGLfloat* params) final;
    void getnUniformivRobustANGLE(GCGLuint program, GCGLint location, GCGLsizei bufSize, GCGLsizei* length, GCGLint* params) final;
    void getnUniformuivRobustANGLE(GCGLuint program, GCGLint location, GCGLsizei bufSize, GCGLsizei* length, GCGLuint* params) final;
    void texParameterIivRobustANGLE(GCGLenum target, GCGLenum pname, GCGLsizei bufSize, const GCGLint* params) final;
    void texParameterIuivRobustANGLE(GCGLenum target, GCGLenum pname, GCGLsizei bufSize, const GCGLuint* params) final;
    void getTexParameterIivRobustANGLE(GCGLenum target, GCGLenum pname, GCGLsizei bufSize, GCGLsizei* length, GCGLint* params) final;
    void getTexParameterIuivRobustANGLE(GCGLenum target, GCGLenum pname, GCGLsizei bufSize, GCGLsizei* length, GCGLuint* params) final;
    void samplerParameterIivRobustANGLE(GCGLuint sampler, GCGLenum pname, GCGLsizei bufSize, const GCGLint* param) final;
    void samplerParameterIuivRobustANGLE(GCGLuint sampler, GCGLenum pname, GCGLsizei bufSize, const GCGLuint* param) final;
    void getSamplerParameterIivRobustANGLE(GCGLuint sampler, GCGLenum pname, GCGLsizei bufSize, GCGLsizei* length, GCGLint* params) final;
    void getSamplerParameterIuivRobustANGLE(GCGLuint sampler, GCGLenum pname, GCGLsizei bufSize, GCGLsizei* length, GCGLuint* params) final;
    void getQueryObjectivRobustANGLE(GCGLuint id, GCGLenum pname, GCGLsizei bufSize, GCGLsizei* length, GCGLint* params) final;
    void getQueryObjecti64vRobustANGLE(GCGLuint id, GCGLenum pname, GCGLsizei bufSize, GCGLsizei* length, GCGLint64* params) final;
    void getQueryObjectui64vRobustANGLE(GCGLuint id, GCGLenum pname, GCGLsizei bufSize, GCGLsizei* length, GCGLuint64* params) final;
    // End of list used by generate-gpup-webgl script.

protected:
    // RemoteGraphicsContextGLProxyBase overrides.
    void waitUntilInitialized() final;

private:
    // Messages to be received.
    void wasCreated(String&& availableExtensions, String&& requestedExtensions);
    void wasLost();
    void wasChanged();

    RemoteGraphicsContextGLProxy(const WebCore::GraphicsContextGLAttributes&);
    bool m_didInitialize { false };
    GraphicsContextGLIdentifier m_graphicsContextGLIdentifier { GraphicsContextGLIdentifier::generate() };
};

// The GCGL types map to following WebKit IPC types. The list is used by generate-gpup-webgl script.
static_assert(std::is_same_v<GCGLenum, uint32_t>);
static_assert(sizeof(GCGLboolean) == sizeof(bool));
static_assert(std::is_same_v<GCGLbitfield, uint32_t>);
static_assert(std::is_same_v<GCGLbyte, int8_t>);
static_assert(std::is_same_v<GCGLubyte, uint8_t>);
static_assert(std::is_same_v<GCGLshort, int16_t>);
static_assert(std::is_same_v<GCGLushort, uint16_t>);
static_assert(std::is_same_v<GCGLint, int32_t>);
static_assert(std::is_same_v<GCGLsizei, int32_t>);
static_assert(std::is_same_v<GCGLuint, uint32_t>);
static_assert(std::is_same_v<GCGLfloat, float>);
static_assert(std::is_same_v<GCGLhalffloat, uint16_t>);
static_assert(std::is_same_v<GCGLclampf, float>);
static_assert(std::is_same_v<GCGLvoid, void>);
static_assert(std::is_same_v<PlatformGLObject, uint32_t>);
static_assert(sizeof(GCGLchar) == sizeof(uint8_t));
static_assert(sizeof(GCGLint64) == sizeof(int64_t));
static_assert(sizeof(GCGLuint64) == sizeof(uint64_t));
// GCGLsync and GCGL*ptr types are pointers. On some platforms, they are 32-bit.
// Currently we hard-code it by using <=, and assume that we do not transfer arrays of the types.
static_assert(sizeof(GCGLintptr) <= sizeof(uint64_t));
static_assert(sizeof(GCGLsizeiptr) <= sizeof(uint64_t));
static_assert(sizeof(GCGLvoidptr) <= sizeof(uint64_t));
static_assert(sizeof(GCGLsync) <= sizeof(uint64_t) && sizeof(GCGLsync) == sizeof(intptr_t));
// End of list used by generate-gpup-webgl script.

} // namespace WebKit

#endif
